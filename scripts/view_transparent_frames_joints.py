from gz.transport import Node
from gz.msgs.boolean_pb2 import Boolean
from gz.msgs.stringmsg_pb2 import StringMsg


# gz service -s /gui/view/frames \
# --reqtype gz.msgs.StringMsg \
# --reptype gz.msgs.Boolean \
# --timeout 2000 \
# --req 'data: "my_model"'

# Example: this depends on the service you want
def call_gui_service(node, service_topic):
    req = StringMsg()
    req.data = "my_model"

    response:Boolean
    result, response = node.request(service_topic, req, StringMsg, Boolean, timeout=1000)  # timeout ms
    print("Result:", result, "\nResponse:", response.data)

def main():
    node = Node()
    call_gui_service(node, "/gui/view/transparent")
    call_gui_service(node, "/gui/view/joints")
    call_gui_service(node, "/gui/view/frames")
  

if __name__ == "__main__":
  main()
