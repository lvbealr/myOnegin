CXX          = g++

SRC          = main.cpp outputText.cpp customStrcmp.cpp sort.cpp textStruct.cpp

BUILD_DIR    = ./build/

TARGET       = ONEGIN.exe
OBJECT       = $(patsubst %.cpp, %.o, $(SRC))
BUILD_OBJ    = $(addprefix $(BUILD_DIR), $(OBJECT))

DED_FLAGS    = -D _DEBUG -ggdb2 -std=c++17 -O0 -Wall -Wextra -Weffc++  									 \
			    -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations	   				 \
				-Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported				     \
				-Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral			 \
				-Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor\
				-Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls\
				-Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2		 \
				-Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types				 \
				-Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef					 \
				-Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros							 \
				-Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing						 \
				-Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation		 \
				-fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer		 \
				-Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla

vpath %.o $(BUILD_DIR)


.PHONY: clean all
all : $(TARGET)

$(TARGET) : $(BUILD_DIR) $(OBJECT)
	$(CXX) $(BUILD_OBJ) -o $(TARGET)

$(BUILD_DIR) :
	mkdir -p build

$(OBJECT) : %.o : %.cpp
	$(CXX) -c $^ -o $(addprefix $(BUILD_DIR), $@)

ded : $(SRC)
	$(CXX) $^ -o $(TARGET) $(DED_FLAGS)

clean :
	rm -f -r $(addprefix $(BUILD_DIR), *.o $(TARGET) *.dSYM)