TARGET = ../../lib/libxv.a
OBJPATH = ../obj
CFLAGS = -std=c++11  -g -O3 -Wno-deprecated-declarations -Wno-deprecated 


LFLAGS =  -lpthread  -lssl -lcrypto -lz -ldl 

 
LLIB = 

OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o, $(notdir $(wildcard *.cpp)))

$(OBJPATH)/%.o : %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(AR) -rcs $(OBJPATH)/$(TARGET) $(OBJS) 

install:
	@cp $(OBJPATH)/$(TARGET) $(LIBPATH) $(LFLAGS)
	
clean:
	@rm -f $(OBJPATH)/*.o
	@rm -f $(TARGET)
	
	
	

