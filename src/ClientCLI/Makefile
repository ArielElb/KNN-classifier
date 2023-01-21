CXX = g++
CPPFLAGS = -I ../
CXXFLAGS = -std=c++11

OBJ = \
	  AlgorithmSettings.o \
	  ClassificationKnn.o \
	  ClientCLI.o \
	  DisplayClassiffications.o \
	  DownloadFile.o \
	  Downloader.o \
	  UploadFile.o

all: $(OBJ)

clean:
	rm -f $(OBJ)

AlgorithmSettings.o: AlgorithmSettings.h

AlgorithmSettings.h: ../General/Command.h ../IO/DefaultIO.h

ClassificationKnn.o: ClassificationKnn.h

ClassificationKnn.h: ../General/Command.h ../IO/DefaultIO.h

ClientCLI.o: ClientCLI.h

ClientCLI.cpp: ../IO/DefaultIO.h

ClientCLI.h: ../General/Command.h AlgorithmSettings.h UploadFile.h \
	DisplayClassiffications.h DownloadFile.h ClassificationKnn.h \
	../IO/FileIO.h

DisplayClassiffications.o: DisplayClassiffications.h

DisplayClassiffications.h: ../General/Command.h ../IO/DefaultIO.h

DownloadFile.o: DownloadFile.h

DownloadFile.h: ../General/Command.h ../IO/DefaultIO.h Downloader.h

Downloader.o: Downloader.h

Downloader.h: ../IO/SocketIO.h ../IO/FileIO.h

UploadFile.o: UploadFile.h

UploadFile.h: ../General/Command.h
