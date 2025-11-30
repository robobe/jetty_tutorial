# Gazebo jetty tutorial

```
gz sim -r empty.sdf -v 4
```

```bash
gz service -s /world/empty/create --reqtype gz.msgs.EntityFactory \
  --reptype gz.msgs.Boolean --timeout 3000 \
  --req 'sdf_filename: "/workspace/models/rrbot.sdf", name: "my_model"'
```

```
gz model --list
```

```bash
gz service -s /world/empty/remove \
  --reqtype gz.msgs.Entity \
  --reptype gz.msgs.Boolean \
  --req 'name: "my_model", type: MODEL'

```

## visual material

```xml
<material>
                    <ambient>0.0 1 0.0 1</ambient>
                    <diffuse>0.0 1 0.0 1</diffuse>
                    <specular>0.0 1 0.0 1</specular>
                </material>
```

- R G B A
- ambient: how the object appears in global light
- diffuse: color when direct light hit the surface
- specular: reflection how the object look when shiny highlight hit it


## Toggle model transparent

```bash
gz service -s /gui/view/transparent \
--reqtype gz.msgs.StringMsg \
--reptype gz.msgs.Boolean \
--timeout 2000 \
--req 'data: "my_model"'
```

## view joints

```bash
gz service -i -s /gui/view/joints
#
Service providers [Address, Request Message Type, Response Message Type]:
  tcp://172.17.0.1:45399, gz.msgs.StringMsg, gz.msgs.Boolean
```

```bash title="joint"
gz service -s /gui/view/joints \
--reqtype gz.msgs.StringMsg \
--reptype gz.msgs.Boolean \
--timeout 2000 \
--req 'data: "my_model"'
```


```bash title="frames"
gz service -s /gui/view/frames \
--reqtype gz.msgs.StringMsg \
--reptype gz.msgs.Boolean \
--timeout 2000 \
--req 'data: "my_model"'
```

---

## Create pyi file from protobuf

```bash
# create virtual environment
pip install mypy-protobuf

cd proto

protoc \
  -I. \
  --python_out=../generated \
  --mypy_out=../generated \
  gz/msgs/*.proto

sudo cp generated/gz/msgs/*.pyi /usr/lib/python3/dist-packages/gz/msgs/
```