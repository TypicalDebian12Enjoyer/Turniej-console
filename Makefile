SRCS = $(shell find srcs -name "*.cpp")
OBJS = $(patsubst srcs/%.cpp, build/obj/%.o, $(SRCS))
DEPS = $(patsubst srcs/%.cpp, build/dep/%.d, $(SRCS))
TARGET = turniej
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -w -MMD -MP

build/obj/%.o: srcs/%.cpp
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(patsubst build/obj/%.o,build/dep/%.d,$@))
	$(CXX) $(CXXFLAGS) -MF$(patsubst build/obj/%.o,build/dep/%.d,$@) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $^ -o $@

run: $(TARGET)
	./$(TARGET)

clean-dep:
	rm -rf build/dep/*

clean-obj:
	rm -rf build/obj/*

clean-bin:
	rm -f $(TARGET)

clean: clean-dep clean-obj clean-bin

.PHONY: all clean clean-bin clean-obj clean-dep run

-include $(DEPS)
