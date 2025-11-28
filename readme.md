🌐 Mini HTTP Server (C++)

A small, beginner-friendly HTTP server built from scratch in C++.
This project marks my first real steps into networking—learning how sockets work, how a request reaches a server, and how to send back a simple HTTP response without using any frameworks.

🚀 Features

Uses AF_INET (IPv4) and SOCK_STREAM (TCP)

Handles basic HTTP GET requests

Sends plain-text HTTP responses

Lightweight and easy to understand

Perfect for beginners exploring networking concepts

📚 How It Works

A socket is created

The server binds to a port

It listens for incoming connections

Accepts a client request

Parses the raw HTTP request

Sends back a valid HTTP response

Closes the connection

This simple flow helps visualize how real servers work under the hood.

🧩 Build & Run
Compile

g++ main.cpp -o server

Run

./server

Then open your browser and visit:
http://localhost:8080

🧠 What I Learned

Basics of TCP socket programming

How raw HTTP requests/headers look

How servers send structured HTTP responses

Why understanding fundamentals makes backend development easier

🔧 Future Improvements

Ability to serve HTML files

Multiple routes (e.g., /, /about)

Logging system

Multithreading for handling multiple clients

Cleaner request parsing

❤️ Why This Exists

This project is me taking my first steps into real networking.
It’s simple, imperfect, and full of learning—and that’s exactly why I built it.

Feel free to explore, fork, improve, or just learn from it.
