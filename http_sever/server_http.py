from flask import Flask, request, jsonify
from flask_cors import CORS

app = Flask(__name__)
CORS(app)  # Cho phép CORS để client như Arduino giao tiếp

# Trạng thái mặc định của các relay
relay_states = {
    "relay1": "off",
    "relay2": "off"
}

def log_request(endpoint, method, data=None):
    """Hàm log thông tin request"""
    print(f"Endpoint: {endpoint}, Method: {method}, Data: {data}")

@app.route('/relay1', methods=['GET', 'POST'])
def control_relay1():
    global relay_states
    endpoint = "/relay1"

    if request.method == 'POST':
        try:
            # Ghi log yêu cầu POST
            log_request(endpoint, "POST", request.get_json())

            # Lấy dữ liệu JSON từ yêu cầu
            data = request.get_json()
            if not data or "state" not in data:
                return jsonify({"error": "Invalid JSON payload. Expecting {'state': 'on'/'off'}"}), 400

            if data["state"] not in ["on", "off"]:
                return jsonify({"error": "Invalid state. Expected 'on' or 'off'"}), 400

            # Cập nhật trạng thái của relay1
            relay_states["relay1"] = data["state"]

            # Trả về phản hồi sau khi cập nhật
            return jsonify({"message": "Relay1 state updated", "state": relay_states["relay1"]}), 200

        except Exception as e:
            return jsonify({"error": "An error occurred", "details": str(e)}), 500

    elif request.method == 'GET':
        # Ghi log yêu cầu GET
        log_request(endpoint, "GET")

        # Kiểm tra tham số query từ URL
        state = request.args.get("state")
        if state in ["on", "off"]:
            relay_states["relay1"] = state  # Cập nhật trạng thái relay1
            return jsonify({"message": "Relay1 state updated via query", "state": relay_states["relay1"]}), 200

        # Nếu không có tham số hợp lệ, trả về trạng thái hiện tại
        return jsonify({"state": relay_states["relay1"]})

@app.route('/relay2', methods=['GET', 'POST'])
def control_relay2():
    global relay_states
    endpoint = "/relay2"

    if request.method == 'POST':
        try:
            # Ghi log yêu cầu POST
            log_request(endpoint, "POST", request.get_json())

            # Lấy dữ liệu JSON từ yêu cầu
            data = request.get_json()
            if not data or "state" not in data:
                return jsonify({"error": "Invalid JSON payload. Expecting {'state': 'on'/'off'}"}), 400

            if data["state"] not in ["on", "off"]:
                return jsonify({"error": "Invalid state. Expected 'on' or 'off'"}), 400

            # Cập nhật trạng thái của relay2
            relay_states["relay2"] = data["state"]

            # Trả về phản hồi sau khi cập nhật
            return jsonify({"message": "Relay2 state updated", "state": relay_states["relay2"]}), 200

        except Exception as e:
            return jsonify({"error": "An error occurred", "details": str(e)}), 500

    elif request.method == 'GET':
        # Ghi log yêu cầu GET
        log_request(endpoint, "GET")

        # Kiểm tra tham số query từ URL
        state = request.args.get("state")
        if state in ["on", "off"]:
            relay_states["relay2"] = state  # Cập nhật trạng thái relay2
            return jsonify({"message": "Relay2 state updated via query", "state": relay_states["relay2"]}), 200

        # Nếu không có tham số hợp lệ, trả về trạng thái hiện tại
        return jsonify({"state": relay_states["relay2"]})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)
