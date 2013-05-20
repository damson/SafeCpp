NAME_EXE = main


SOURCES		=	main.cpp		\
			CondVar.cpp		\
			ThreadPool.cpp		\
			Mutex.cpp		\
			SafeQueue.cpp		\
			Task.cpp		\
			Exception.cpp		\
			SafeCout.cpp		\
			SafeCerr.cpp		\
			Thread.cpp

SRCDIR		=	src/
INCDIR		=	include/
LIBDIR		=	lib/
BINDIR		=	bin/

CXXFLAGS	=	-W -Wall -Wextra
LDFLAGS		=	-pthread -lrt
OPTFLAGS	=
INCFLAGS	=	-I $(INCDIR)

SRCS		=	$(addprefix $(SRCDIR),$(SOURCES))
OBJS		=	$(SRCS:.cpp=.o)

CXX		=	g++
CP		=	@cp
FIND		=	@find
MD		=	@mkdir -p
RM		=	rm -fr

MAKE		=	@make

%.o:			%.cpp
			$(CXX) $(CXXFLAGS) $(INCFLAGS) $(OPTFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
			$(MD) $(BINDIR)
			$(CXX) $(LDFLAGS) $(OBJS) -o $(NAME)
			$(CP) $(NAME) $(BINDIR)

genLib:
			$(MAKE) -C $(LIBDIR) all

clean:
			$(RM) $(OBJS)
			$(RM) $(BINDIR)
			$(FIND) . -name "*~" -delete -print

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
