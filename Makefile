# Компілятор і опції
CXX = g++
CXXFLAGS = -Wall -Iinclude

# Шляхи
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Файли
LIBRARY = $(BINDIR)/libcalculator.a
EXECUTABLE = $(BINDIR)/calculator
OBJECTS = $(OBJDIR)/calculator.o $(OBJDIR)/main.o

# Правило за замовчуванням
all: $(EXECUTABLE)

# Компіляція виконуваного файлу
$(EXECUTABLE): $(OBJECTS) | $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Компіляція об'єктних файлів
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Статична бібліотека
$(LIBRARY): $(OBJDIR)/calculator.o | $(BINDIR)
	ar rcs $@ $^

# Створення директорій
$(OBJDIR):
	mkdir -p $@

$(BINDIR):
	mkdir -p $@

# Очищення
clean:
	rm -rf $(OBJDIR) $(BINDIR)
