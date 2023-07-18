import socket

# Create a socket object
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to a specific address and port
server_address = ('localhost', 6666)
server_socket.bind(server_address)

# Listen for incoming connections
server_socket.listen(5)

while True:
    print('Waiting for a client to connect...')
    
    # Accept a client connection
    client_socket, client_address = server_socket.accept()
    print('Connected client:', client_address)
    
    try:
        while True:
            # Receive data from the client
            data = client_socket.recv(1024)
        
            if data:
                print('Received data:', data.decode('utf-8'))
                
                # Send a response back to the client
                response = 'Hello from the server!'
                client_socket.send(response.encode('utf-8'))
            else:
                # No more data from client
                print('Client disconnected:', client_address)
                break

    finally:
        # Close the connection
        client_socket.close()