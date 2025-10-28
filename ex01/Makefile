# 실행 파일 이름
NAME = phonebook

# C++ 컴파일러
CXX = c++

# 컴파일러 플래그
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# 소스 파일
SRCS = phonebook.cpp

# 오브젝트 파일 (소스 파일 이름에서 .cpp를 .o로 변경)
OBJS = $(SRCS:.cpp=.o)

# 기본 규칙: all
all: $(NAME)

# 실행 파일을 만드는 규칙
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# .cpp 파일을 .o 파일로 컴파일하는 규칙
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 컴파일 중간 생성물(.o 파일)을 삭제하는 규칙
clean:
	rm -f $(OBJS)

# 최종 실행 파일까지 모두 삭제하는 규칙
fclean: clean
	rm -f $(NAME)

# 전부 삭제하고 다시 컴파일하는 규칙
re: fclean all

.PHONY: all clean fclean re