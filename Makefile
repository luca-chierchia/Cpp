vpath %.cpp ./src

src = main.cpp

objects = $(patsubst %.cpp,obj/%.o,$(src))

$(objects): | obj

obj:
	@mkdir -p $@

obj/%.o : %.cpp
	@echo $<
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	mkdir bin
	@$(CXX) $(LDFLAGS) -o bin/main $(objects)

clean:
	rm -fr bin/ obj/

