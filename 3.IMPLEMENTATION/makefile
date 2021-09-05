PROJECT_NAME = ElectronicCircuitAnalyzer
TEST_PROJECT_NAME = TEST_$(PROJECT_NAME)

BUILD_DIR = Build

SRC = src/battery_data.c\
src/capacitor.c\
src/inductor.c\
src/paralell.c\
src/powerAndLife.c\
src/reg4band.c\
src/reg5band.c\
src/RLC.c\
src/series.c

COV_SRC = test.c

TEST_SRC = test/test.c\
unity/unity.c

INC_H = inc
INC_T = unity
# for makefile to run in both windows and linux build
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

.PHONY : all test coverage run clean doc

all:$(BUILD_DIR)
	gcc MainMenu.c -I $(INC_H) $(SRC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC)) -lm
# to run the project
run: all
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))
# to make the build documentation
doc:
	make -C doc
$(BUILD_DIR):
	mkdir $(BUILD_DIR)
# for unit testing
test:
	gcc -I $(INC_H) -I $(INC_T) $(TEST_SRC) $(SRC) -o $(call FixPath,$(TEST_PROJECT_NAME).$(EXEC)) -lm
	./$(call FixPath,$(TEST_PROJECT_NAME).$(EXEC))
# for CI code coverage
coverage:
	cp test/test.c .
	gcc -fprofile-arcs -ftest-coverage -I $(INC_H) -I $(INC_T) unity/unity.c test.c $(SRC) -o $(call FixPath, $(TEST_PROJECT_NAME).$(EXEC)) -lm
	$(call FixPath, ./$(TEST_PROJECT_NAME).$(EXEC))
	gcov -a $(COV_SRC)
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov
	$(RM) *.DAT
	$(RM) test.c
# for valgrind testing
valgrind:
	valgrind ./$(TEST_PROJECT_NAME).$(EXEC)

clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/*)
	make clean -C doc
	rmdir $(BUILD_DIR) doc/html
	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT)