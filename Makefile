CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude -pthread

SRC = main.cpp \
      src/file_utils.cpp \
      src/parser.cpp \
      src/response.cpp \
      src/router.cpp \
      src/thread_pool.cpp

TARGET = server

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)