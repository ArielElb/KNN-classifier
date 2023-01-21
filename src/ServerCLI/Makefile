CXX = g++
CPPFLAGS = -I ../
CXXFLAGS = -std=c++11

OBJ = \
	  ClassifyCommand.o \
	  ConnectionHandler.o \
	  DisplayCommand.o \
	  DownloadCommand.o \
	  ServerCLI.o \
	  SettingsCommand.o \
	  UploadCommand.o \
	  Uploader.o \
	  util.o

all: $(OBJ)

clean:
	rm -f $(OBJ)

ClassifyCommand.o: ClassifyCommand.h

ClassifyCommand.h: ../General/Command.h

ConnectionHandler.o: ConnectionHandler.h

ConnectionHandler.h: ServerCLI.h

DisplayCommand.o: DisplayCommand.h

DisplayCommand.h: ../General/Command.h

DownloadCommand.o: DownloadCommand.h

DownloadCommand.h: ../General/Command.h

ServerCLI.o: ServerCLI.h

ServerCLI.h: UploadCommand.h ../General/Command.h SettingsCommand.h \
	ClassifyCommand.h DisplayCommand.h DownloadCommand.h

SettingsCommand.o: SettingsCommand.h

SettingsCommand.h: ../General/Command.h ../General/Database.h util.h

UploadCommand.o: UploadCommand.h

UploadCommand.h: ../General/Command.h

Uploader.o: Uploader.h

util.o: util.h
