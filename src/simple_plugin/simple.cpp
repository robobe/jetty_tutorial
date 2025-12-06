#include <gz/sim/System.hh>
#include <gz/sim/Model.hh>
#include <gz/sim/Link.hh>
#include <gz/sim/Joint.hh>

#include <gz/sim/components/Link.hh>
#include <gz/sim/components/Name.hh>
#include <gz/sim/components/Joint.hh>
#include <gz/sim/components/ParentEntity.hh>

#include <gz/plugin/Register.hh>
#include <iostream>

using namespace gz;
using namespace sim;

/////////////////////////////////////////////////
class ListLinksAndJointsPlugin
  : public System,
    public ISystemConfigure,
    public ISystemPreUpdate
{
public:

  void Configure(const Entity &_entity,
                 const std::shared_ptr<const sdf::Element> &/*_sdf*/,
                 EntityComponentManager &_ecm,
                 EventManager &/*_event*/) override
  {
    this->model = Model(_entity);
    std::cout << "Model loaded: " << this->model.Name(_ecm) << "\n";
  }

  void PreUpdate(const UpdateInfo &,
                 EntityComponentManager &_ecm) override
  {
    if (this->printed)
      return;

    this->printed = true;

    std::cout << "----------------------------------------\n";
    std::cout << " Listing links for model: "
              << this->model.Name(_ecm) << "\n";

    // ---------------------------------------
    // LIST LINKS
    // ---------------------------------------
    _ecm.Each<components::Link, components::ParentEntity>(
      [&](const Entity &entity,
          const components::Link *,
          const components::ParentEntity *parent) -> bool
      {
        if (parent->Data() == this->model.Entity())
        {
          auto name = _ecm.Component<components::Name>(entity);
          std::cout << " Link: " << name->Data() << "\n";
        }
        return true;
      });

    // ---------------------------------------
    // LIST JOINTS
    // ---------------------------------------
    std::cout << "----------------------------------------\n";
    std::cout << " Listing joints:\n";

    _ecm.Each<components::Joint, components::ParentEntity>(
      [&](const Entity &entity,
          const components::Joint *,
          const components::ParentEntity *parent) -> bool
      {
        if (parent->Data() == this->model.Entity())
        {
          auto name = _ecm.Component<components::Name>(entity);
          std::cout << " Joint: " << name->Data() << "\n";
        }
        return true;
      });

    std::cout << "----------------------------------------\n";
  }

private:
  Model model{kNullEntity};
  bool printed = false;
};

GZ_ADD_PLUGIN(ListLinksAndJointsPlugin,
              System,
              ListLinksAndJointsPlugin::ISystemConfigure,
              ListLinksAndJointsPlugin::ISystemPreUpdate)

GZ_ADD_PLUGIN_ALIAS(ListLinksAndJointsPlugin,
                    "gz::sim::systems::ListLinksAndJointsPlugin")
