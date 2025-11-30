from gz.transport import Node
from gz.msgs.entity_factory_pb2   import EntityFactory
from gz.msgs.boolean_pb2 import Boolean

node = Node()

# Example: this depends on the service you want
service_name = "/world/empty/create"   # just an example name
req = EntityFactory()

req.name = "my_model"
req.sdf_filename="/workspace/models/rrbot.sdf"

response:Boolean
result, response = node.request(service_name, req, EntityFactory, Boolean, timeout=1000)  # timeout ms
print("Result:", result, "\nResponse:", response.data)

