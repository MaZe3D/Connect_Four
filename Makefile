COMPILER_AND_LINKER := g++
SOURCE_FILE_EXTENSION := .cpp

# caution: "make clean" removes OBJ and BIN directories completely
SRC_DIRECTORY := src
OBJ_DIRECTORY := .obj
BIN_DIRECTORY := bin

DEFAULT_BUILD_TARGET := release
OTHER_BUILD_TARGETS := debug test

COMPILER_FLAGS := -Wall -std=c++20 -I $(SRC_DIRECTORY)
LINKER_FLAGS :=

debug:   COMPILER_FLAGS += -O0 -g
release: COMPILER_FLAGS += -O2



# ---------------------------------- make magic - do not touch ----------------------------------
source_files := \
	$(wildcard $(SRC_DIRECTORY)/*$(SOURCE_FILE_EXTENSION)) \
	$(wildcard $(SRC_DIRECTORY)/*/*$(SOURCE_FILE_EXTENSION)) \
	$(wildcard $(SRC_DIRECTORY)/*/*/*$(SOURCE_FILE_EXTENSION)) \
	$(wildcard $(SRC_DIRECTORY)/*/*/*/*$(SOURCE_FILE_EXTENSION)) \
	$(wildcard $(SRC_DIRECTORY)/*/*/*/*/*$(SOURCE_FILE_EXTENSION))

define create_build_target
object_files_$1 := $$(patsubst $$(SRC_DIRECTORY)/%$$(SOURCE_FILE_EXTENSION),$$(OBJ_DIRECTORY)/$1/%.o,$$(source_files))

.PHONY: $1 run_$1
$1: $$(BIN_DIRECTORY)/$1
$$(BIN_DIRECTORY)/$1: $$(object_files_$1)
	@mkdir -p $$(@D)
	$$(COMPILER_AND_LINKER) $$(strip $$(LINKER_FLAGS) $$^ -o $$@)

$$(OBJ_DIRECTORY)/$1/%.o: $$(SRC_DIRECTORY)/%$$(SOURCE_FILE_EXTENSION)
	@mkdir -p $$(@D)
	$$(COMPILER_AND_LINKER) $$(strip $$(COMPILER_FLAGS) -c $$< -o $$@)

run_$1: $$(BIN_DIRECTORY)/$1
	$$<
endef

$(foreach build_target,$(DEFAULT_BUILD_TARGET) $(OTHER_BUILD_TARGETS),\
	$(eval $(call create_build_target,$(build_target))))

.PHONY: clean run
clean:
	rm -rf $(OBJ_DIRECTORY) $(BIN_DIRECTORY)

run: run_$(DEFAULT_BUILD_TARGET)
