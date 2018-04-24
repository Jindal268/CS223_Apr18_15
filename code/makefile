CXX = g++
CXXFLAGS = -Wall -g
$Pub.exe: $main.o $paper.o $database.o $user.o $admin.o $system.o
	$(CXX) $(CXXFLAGS) -o Pub.exe main.o paper.o database.o user.o admin.o system.o
$main.o: main.cpp paper.h database.h user.h admin.h system.h
	$(CXX) $(CXXFLAGS) -c main.cpp
$paper.o: paper.cpp paper.h
	$(CXX) $(CXXFLAGS) -c paper.cpp
$database.o: database.cpp paper.h database.h user.h admin.h
	$(CXX) $(CXXFLAGS) -c database.cpp
$user.o: user.cpp user.h system.h
	$(CXX) $(CXXFLAGS) -c user.cpp
$admin.o: admin.cpp paper.h database.h user.h admin.h system.h
	$(CXX) $(CXXFLAGS) -c admin.cpp
$system.o: system.cpp system.h database.h paper.h admin.h user.h
	$(CXX) $(CXXFLAGS) -c system.cpp
