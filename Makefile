# Compiler
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Directories
SRCDIR = cpp_files
INCDIR = header
BINDIR = bin
IMAGEDIR = images

# Source and header files
SRCS = $(wildcard $(SRCDIR)/*.cpp)
EXES = $(SRCS:$(SRCDIR)/%.cpp=$(BINDIR)/%)

# Targets
all: build images

# Ensure bin and images directories exist
$(IMAGEDIR):
	@mkdir -p $(IMAGEDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)

# Pattern rule to create executables from object files
$(BINDIR)/%: $(SRCDIR)/%.cpp $(HEADERS) | $(BINDIR)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) $< -o $@

# Build all executables
build: $(SRCDIR) $(BINDIR) $(EXES)

# Generate ppm images
images: $(IMAGEDIR) $(EXES)
	@mkdir -p $(IMAGEDIR)
	for exe in $(EXES); do \
		./$$exe > $(IMAGEDIR)/$$(basename $$exe).ppm; \
	done

# Clean up
clean_obj:
	rm -rf $(BINDIR)

clean_images:
	rm -rf $(IMAGEDIR)

clean: clean_images clean_obj

.PHONY: all build images clean_obj clean_images
