CC = g++ -std=c++11
IT_SRC = Interpreter/
LY_SRC = Interpreter/LEXYACC/
API_SRC = API/
minisql : main.cpp MiniSQL.h \
		  $(LY_SRC)yacc.cpp $(LY_SRC)yacc.hpp $(LY_SRC)lex.cpp \
		  $(IT_SRC)CST.cpp $(IT_SRC)CST.h $(IT_SRC)interpreter.h \
		  $(API_SRC)API.cpp $(API_SRC)API.h
	$(CC) -o minisql main.cpp $(LY_SRC)yacc.cpp  $(LY_SRC)lex.cpp \
			 $(IT_SRC)CST.cpp $(API_SRC)API.cpp