BIN_ROOT = bin
BUILD_ROOT = build
SRC_ROOT = src

CXX = clang++-5.0

GFLAGS_WARN_FLAGS = \
    -Wno-exit-time-destructors \
	-Wno-global-constructors \
	-Wno-missing-variable-declarations \
	-Wno-undefined-func-template \

WARN_FLAGS = \
    -Wall \
    -Werror \
    -Weverything \
    -Wextra \
    -Wpedantic \
    -Wno-c++98-compat \
    -Wno-c++98-compat-pedantic \
    -Wno-disabled-macro-expansion \
    -Wno-double-promotion \
    -Wno-format-nonliteral \
    -Wno-padded \
    $(GFLAGS_WARN_FLAGS) \

CXX_FLAGS = \
    -Isrc/ \
    -Isrc/ext/ \
    -O3 \
    -std=c++17 \
    $(WARN_FLAGS) \

LD_FLAGS = \
    -lboost_system \
    -lboost_thread \
    -lcurl \
    -lgflags \
    -lpthread \

MAIN_SOURCES = $(shell find $$SRC_ROOT -type f -name "*.cc" | \
    xargs grep "^int main" | cut -d: -f1 | cut -c3- | sort)

LIB_SOURCES = $(shell find $$SRC_ROOT -type f -name "*.cc" | \
    xargs grep -L "^int main" | cut -c3- | sort)

OBJS = $(patsubst $(SRC_ROOT)/%.cc, $(BUILD_ROOT)/%.o, $(LIB_SOURCES))

HEADERS = $(shell find src/ -type f -name "*.h" | sort)

BINS = $(patsubst $(SRC_ROOT)/%.cc, $(BIN_ROOT)/%, $(MAIN_SOURCES))

$(BUILD_ROOT)/%.o: $(SRC_ROOT)/%.cc $(HEADERS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

$(BIN_ROOT)/%: $(SRC_ROOT)/%.cc $(OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXX_FLAGS) $(OBJS) $< -o $@ $(LD_FLAGS)

.SECONDARY: $(OBJS)

all: $(BINS)

clean:
	@rm -rf $(BIN_ROOT) $(BUILD_ROOT)

print-%:
	@echo $* = $($*)
