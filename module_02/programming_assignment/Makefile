PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

OBJS = csc450-module-02.o

ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g -O0
else ifeq ($(BUILD_MODE),run)
	CFLAGS += -O2
else ifeq ($(BUILD_MODE),profile)
	CFLAGS += -g -pg -fprofile-arcs -ftest-coverage
	LDFLAGS += -pg -fprofile-arcs -ftest-coverage
	EXTRA_CLEAN += csc450-module-02.gcda csc450-module-02.gcno $(PROJECT_ROOT)gmon.out
	EXTRA_CMDS = rm -rf csc450-module-02.gcda
else
    $(error Build mode $(BUILD_MODE) not supported by this Makefile)
endif

all:	csc450-module-02

csc450-module-02:	$(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^
	$(EXTRA_CMDS)

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -fr csc450-module-02 $(OBJS) $(EXTRA_CLEAN)
