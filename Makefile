CXX = g++
CPPFLAGS = -I .
CXXFLAGS = -std=c++11

SUBDIRS = ClientCLI Distances General IO ServerCLI

SHARED_OBJ = \
			 General/Vector.o \
			 IO/FileIO.o \
			 IO/SocketIO.o

CLIENT_OBJ = \
			 $(SHARED_OBJ) \
			 General/client.o \
			 ClientCLI/AlgorithmSettings.o \
			 ClientCLI/ClassificationKnn.o \
			 ClientCLI/ClientCLI.o \
			 ClientCLI/DisplayClassiffications.o \
			 ClientCLI/DownloadFile.o \
			 ClientCLI/Downloader.o \
			 ClientCLI/UploadFile.o

SERVER_OBJ = \
			 $(SHARED_OBJ) \
			 General/Comparator.o \
			 General/Database.o \
			 General/server.o \
			 Distances/AUC.o \
			 Distances/CAN.o \
			 Distances/CHB.o \
			 Distances/MAN.o \
			 Distances/MIN.o \
			 ServerCLI/ClassifyCommand.o \
			 ServerCLI/ConnectionHandler.o \
			 ServerCLI/DisplayCommand.o \
			 ServerCLI/DownloadCommand.o \
			 ServerCLI/ServerCLI.o \
			 ServerCLI/SettingsCommand.o \
			 ServerCLI/UploadCommand.o \
			 ServerCLI/Uploader.o \
			 ServerCLI/util.o


.PHONY: all clean $(SUBDIRS)

all: server.out client.out

client.out: clientMain.o $(SUBDIRS)
	$(CXX) $(CXXFLAGS) -o $@ $< $(CLIENT_OBJ)

server.out: serverMain.o $(SUBDIRS)
	$(CXX) $(CXXFLAGS) -o $@ $< $(SERVER_OBJ)

$(SUBDIRS):
	$(MAKE) -C $@

clean:
	@for dir in $(SUBDIRS); do $(MAKE) -C $${dir} clean; done
	@rm -f *.o server.out client.out
