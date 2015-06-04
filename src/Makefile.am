AM_CPPFLAGS = -I$(top_srcdir)/src/database
AM_CPPFLAGS += -I$(top_srcdir)/src/parser
AM_CPPFLAGS += -I$(top_srcdir)/src/server
AM_CPPFLAGS += -I$(top_srcdir)/src/utilities
CFLAGS += -std=c++11 -g -Wall 
LDFLAGS += -pthread -lmysqlcppconn -lboost_system

bin_PROGRAMS = Server

Server_SOURCES = main.cpp database/Database.cpp utilities/print.cpp \
		 parser/parser.cpp server/Player.cpp utilities/checks.cpp \
		 server/Players.cpp server/Connection.cpp server/Table.cpp \
		 server/ProcessingCommand.cpp server/Tables.cpp
