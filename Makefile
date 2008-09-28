#############################################################################
# Makefile for building: krhash
# Generated by qmake (2.01a) (Qt 4.4.2) on: Sun Sep 28 10:04:40 2008
# Project:  krhash.pro
# Template: app
# Command: /usr/bin/qmake -unix -o Makefile krhash.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -march=pentium-m -msse3 -O2 -pipe -fomit-frame-pointer -ggdb -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -march=pentium-m -msse3 -O2 -pipe -fomit-frame-pointer -ggdb -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/qt4 -lssl -lQtGui -L/usr/lib/qt4 -L/usr/X11R6/lib -lpng -lSM -lICE -lXrender -lXrandr -lXinerama -lfreetype -lfontconfig -lXext -lX11 -lQtCore -lz -lm -lrt -ldl -lpthread
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		MainWindow.cpp \
		AbstractAlgo.cpp \
		AlgoMd5.cpp \
		AlgoMd4.cpp \
		AlgoSha1.cpp \
		AlgoLm.cpp \
		AbstractAttack.cpp \
		BrutForceAttack.cpp \
		MetaString.cpp \
		HashListWidget.cpp \
		CommonAttack.cpp \
		DictionaryAttack.cpp \
		MetaString2.cpp \
		AbstractString.cpp \
		InfoWidget.cpp \
		ConfigBrutForceWidget.cpp \
		ConfigAttackDialog.cpp \
		ConfigDictionaryWidget.cpp \
		ConfigAbstractAttackWidget.cpp moc_MainWindow.cpp \
		moc_AbstractAttack.cpp \
		moc_HashListWidget.cpp \
		moc_InfoWidget.cpp \
		moc_ConfigAttackDialog.cpp \
		moc_ConfigBrutForceWidget.cpp \
		moc_ConfigDictionaryWidget.cpp \
		moc_ConfigAbstractAttackWidget.cpp
OBJECTS       = main.o \
		MainWindow.o \
		AbstractAlgo.o \
		AlgoMd5.o \
		AlgoMd4.o \
		AlgoSha1.o \
		AlgoLm.o \
		AbstractAttack.o \
		BrutForceAttack.o \
		MetaString.o \
		HashListWidget.o \
		CommonAttack.o \
		DictionaryAttack.o \
		MetaString2.o \
		AbstractString.o \
		InfoWidget.o \
		ConfigBrutForceWidget.o \
		ConfigAttackDialog.o \
		ConfigDictionaryWidget.o \
		ConfigAbstractAttackWidget.o \
		moc_MainWindow.o \
		moc_AbstractAttack.o \
		moc_HashListWidget.o \
		moc_InfoWidget.o \
		moc_ConfigAttackDialog.o \
		moc_ConfigBrutForceWidget.o \
		moc_ConfigDictionaryWidget.o \
		moc_ConfigAbstractAttackWidget.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		krhash.pro
QMAKE_TARGET  = krhash
DESTDIR       = 
TARGET        = krhash

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: krhash.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/lib/qt4/libQtGui.prl \
		/usr/lib/qt4/libQtCore.prl
	$(QMAKE) -unix -o Makefile krhash.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/lib/qt4/libQtGui.prl:
/usr/lib/qt4/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile krhash.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/krhash1.0.0 || $(MKDIR) .tmp/krhash1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/krhash1.0.0/ && $(COPY_FILE) --parents MainWindow.h AbstractAlgo.h AlgoMd5.h AlgoMd4.h AlgoSha1.h AlgoLm.h AbstractAttack.h BrutForceAttack.h MetaString.h HashListWidget.h CommonAttack.h DictionaryAttack.h MetaString2.h AbstractString.h InfoWidget.h ConfigAttackDialog.h ConfigBrutForceWidget.h ConfigDictionaryWidget.h ConfigAbstractAttackWidget.h .tmp/krhash1.0.0/ && $(COPY_FILE) --parents main.cpp MainWindow.cpp AbstractAlgo.cpp AlgoMd5.cpp AlgoMd4.cpp AlgoSha1.cpp AlgoLm.cpp AbstractAttack.cpp BrutForceAttack.cpp MetaString.cpp HashListWidget.cpp CommonAttack.cpp DictionaryAttack.cpp MetaString2.cpp AbstractString.cpp InfoWidget.cpp ConfigBrutForceWidget.cpp ConfigAttackDialog.cpp ConfigDictionaryWidget.cpp ConfigAbstractAttackWidget.cpp .tmp/krhash1.0.0/ && (cd `dirname .tmp/krhash1.0.0` && $(TAR) krhash1.0.0.tar krhash1.0.0 && $(COMPRESS) krhash1.0.0.tar) && $(MOVE) `dirname .tmp/krhash1.0.0`/krhash1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/krhash1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_MainWindow.cpp moc_AbstractAttack.cpp moc_HashListWidget.cpp moc_InfoWidget.cpp moc_ConfigAttackDialog.cpp moc_ConfigBrutForceWidget.cpp moc_ConfigDictionaryWidget.cpp moc_ConfigAbstractAttackWidget.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_MainWindow.cpp moc_AbstractAttack.cpp moc_HashListWidget.cpp moc_InfoWidget.cpp moc_ConfigAttackDialog.cpp moc_ConfigBrutForceWidget.cpp moc_ConfigDictionaryWidget.cpp moc_ConfigAbstractAttackWidget.cpp
moc_MainWindow.cpp: AbstractAttack.h \
		AbstractAlgo.h \
		AlgoMd4.h \
		AlgoMd5.h \
		AlgoSha1.h \
		AlgoLm.h \
		BrutForceAttack.h \
		CommonAttack.h \
		AbstractString.h \
		MetaString.h \
		DictionaryAttack.h \
		MetaString2.h \
		HashListWidget.h \
		InfoWidget.h \
		ConfigAttackDialog.h \
		ConfigBrutForceWidget.h \
		ConfigAbstractAttackWidget.h \
		ConfigDictionaryWidget.h \
		MainWindow.h
	/usr/bin/moc $(DEFINES) $(INCPATH) MainWindow.h -o moc_MainWindow.cpp

moc_AbstractAttack.cpp: AbstractAlgo.h \
		AbstractAttack.h
	/usr/bin/moc $(DEFINES) $(INCPATH) AbstractAttack.h -o moc_AbstractAttack.cpp

moc_HashListWidget.cpp: AbstractAttack.h \
		AbstractAlgo.h \
		HashListWidget.h
	/usr/bin/moc $(DEFINES) $(INCPATH) HashListWidget.h -o moc_HashListWidget.cpp

moc_InfoWidget.cpp: AbstractAttack.h \
		AbstractAlgo.h \
		InfoWidget.h
	/usr/bin/moc $(DEFINES) $(INCPATH) InfoWidget.h -o moc_InfoWidget.cpp

moc_ConfigAttackDialog.cpp: ConfigBrutForceWidget.h \
		ConfigAbstractAttackWidget.h \
		AbstractAttack.h \
		AbstractAlgo.h \
		ConfigDictionaryWidget.h \
		ConfigAttackDialog.h
	/usr/bin/moc $(DEFINES) $(INCPATH) ConfigAttackDialog.h -o moc_ConfigAttackDialog.cpp

moc_ConfigBrutForceWidget.cpp: ConfigAbstractAttackWidget.h \
		AbstractAttack.h \
		AbstractAlgo.h \
		ConfigBrutForceWidget.h
	/usr/bin/moc $(DEFINES) $(INCPATH) ConfigBrutForceWidget.h -o moc_ConfigBrutForceWidget.cpp

moc_ConfigDictionaryWidget.cpp: ConfigAbstractAttackWidget.h \
		AbstractAttack.h \
		AbstractAlgo.h \
		ConfigDictionaryWidget.h
	/usr/bin/moc $(DEFINES) $(INCPATH) ConfigDictionaryWidget.h -o moc_ConfigDictionaryWidget.cpp

moc_ConfigAbstractAttackWidget.cpp: AbstractAttack.h \
		AbstractAlgo.h \
		ConfigAbstractAttackWidget.h
	/usr/bin/moc $(DEFINES) $(INCPATH) ConfigAbstractAttackWidget.h -o moc_ConfigAbstractAttackWidget.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

main.o: main.cpp MainWindow.h \
		AbstractAttack.h \
		AbstractAlgo.h \
		AlgoMd4.h \
		AlgoMd5.h \
		AlgoSha1.h \
		AlgoLm.h \
		BrutForceAttack.h \
		CommonAttack.h \
		AbstractString.h \
		MetaString.h \
		DictionaryAttack.h \
		MetaString2.h \
		HashListWidget.h \
		InfoWidget.h \
		ConfigAttackDialog.h \
		ConfigBrutForceWidget.h \
		ConfigAbstractAttackWidget.h \
		ConfigDictionaryWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

MainWindow.o: MainWindow.cpp MainWindow.h \
		AbstractAttack.h \
		AbstractAlgo.h \
		AlgoMd4.h \
		AlgoMd5.h \
		AlgoSha1.h \
		AlgoLm.h \
		BrutForceAttack.h \
		CommonAttack.h \
		AbstractString.h \
		MetaString.h \
		DictionaryAttack.h \
		MetaString2.h \
		HashListWidget.h \
		InfoWidget.h \
		ConfigAttackDialog.h \
		ConfigBrutForceWidget.h \
		ConfigAbstractAttackWidget.h \
		ConfigDictionaryWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MainWindow.o MainWindow.cpp

AbstractAlgo.o: AbstractAlgo.cpp AbstractAlgo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AbstractAlgo.o AbstractAlgo.cpp

AlgoMd5.o: AlgoMd5.cpp AlgoMd5.h \
		AbstractAlgo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AlgoMd5.o AlgoMd5.cpp

AlgoMd4.o: AlgoMd4.cpp AlgoMd4.h \
		AbstractAlgo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AlgoMd4.o AlgoMd4.cpp

AlgoSha1.o: AlgoSha1.cpp AlgoSha1.h \
		AbstractAlgo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AlgoSha1.o AlgoSha1.cpp

AlgoLm.o: AlgoLm.cpp AlgoLm.h \
		AbstractAlgo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AlgoLm.o AlgoLm.cpp

AbstractAttack.o: AbstractAttack.cpp AbstractAttack.h \
		AbstractAlgo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AbstractAttack.o AbstractAttack.cpp

BrutForceAttack.o: BrutForceAttack.cpp BrutForceAttack.h \
		CommonAttack.h \
		AbstractAttack.h \
		AbstractAlgo.h \
		AbstractString.h \
		MetaString.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BrutForceAttack.o BrutForceAttack.cpp

MetaString.o: MetaString.cpp MetaString.h \
		AbstractString.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MetaString.o MetaString.cpp

HashListWidget.o: HashListWidget.cpp HashListWidget.h \
		AbstractAttack.h \
		AbstractAlgo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o HashListWidget.o HashListWidget.cpp

CommonAttack.o: CommonAttack.cpp CommonAttack.h \
		AbstractAttack.h \
		AbstractAlgo.h \
		AbstractString.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CommonAttack.o CommonAttack.cpp

DictionaryAttack.o: DictionaryAttack.cpp DictionaryAttack.h \
		CommonAttack.h \
		AbstractAttack.h \
		AbstractAlgo.h \
		AbstractString.h \
		MetaString2.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DictionaryAttack.o DictionaryAttack.cpp

MetaString2.o: MetaString2.cpp MetaString2.h \
		AbstractString.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MetaString2.o MetaString2.cpp

AbstractString.o: AbstractString.cpp AbstractString.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AbstractString.o AbstractString.cpp

InfoWidget.o: InfoWidget.cpp InfoWidget.h \
		AbstractAttack.h \
		AbstractAlgo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o InfoWidget.o InfoWidget.cpp

ConfigBrutForceWidget.o: ConfigBrutForceWidget.cpp ConfigBrutForceWidget.h \
		ConfigAbstractAttackWidget.h \
		AbstractAttack.h \
		AbstractAlgo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ConfigBrutForceWidget.o ConfigBrutForceWidget.cpp

ConfigAttackDialog.o: ConfigAttackDialog.cpp ConfigAttackDialog.h \
		ConfigBrutForceWidget.h \
		ConfigAbstractAttackWidget.h \
		AbstractAttack.h \
		AbstractAlgo.h \
		ConfigDictionaryWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ConfigAttackDialog.o ConfigAttackDialog.cpp

ConfigDictionaryWidget.o: ConfigDictionaryWidget.cpp ConfigDictionaryWidget.h \
		ConfigAbstractAttackWidget.h \
		AbstractAttack.h \
		AbstractAlgo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ConfigDictionaryWidget.o ConfigDictionaryWidget.cpp

ConfigAbstractAttackWidget.o: ConfigAbstractAttackWidget.cpp ConfigAbstractAttackWidget.h \
		AbstractAttack.h \
		AbstractAlgo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ConfigAbstractAttackWidget.o ConfigAbstractAttackWidget.cpp

moc_MainWindow.o: moc_MainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_MainWindow.o moc_MainWindow.cpp

moc_AbstractAttack.o: moc_AbstractAttack.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_AbstractAttack.o moc_AbstractAttack.cpp

moc_HashListWidget.o: moc_HashListWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_HashListWidget.o moc_HashListWidget.cpp

moc_InfoWidget.o: moc_InfoWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_InfoWidget.o moc_InfoWidget.cpp

moc_ConfigAttackDialog.o: moc_ConfigAttackDialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ConfigAttackDialog.o moc_ConfigAttackDialog.cpp

moc_ConfigBrutForceWidget.o: moc_ConfigBrutForceWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ConfigBrutForceWidget.o moc_ConfigBrutForceWidget.cpp

moc_ConfigDictionaryWidget.o: moc_ConfigDictionaryWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ConfigDictionaryWidget.o moc_ConfigDictionaryWidget.cpp

moc_ConfigAbstractAttackWidget.o: moc_ConfigAbstractAttackWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ConfigAbstractAttackWidget.o moc_ConfigAbstractAttackWidget.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

