# Gazebo harmonic tutorial

- create `.gz` folder and share with docker


```
gz service -s /world/empty/create --reqtype gz.msgs.EntityFactory \
  --reptype gz.msgs.Boolean --timeout 3000 \
  --req 'sdf_filename: "/workspace/models/rrbot.sdf", name: "my_model"'
```

```bash
gz service -s /world/empty/remove \
  --reqtype gz.msgs.Entity \
  --reptype gz.msgs.Boolean \
  --req 'name: "my_model"'

```