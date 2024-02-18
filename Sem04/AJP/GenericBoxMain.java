class GenericBoxMain {
    public static void main(String[] args) {

        GenericBox<Integer> intItem = new GenericBox<>(42);
        printBox(intItem);

        GenericBox<String> strItem = new GenericBox<>("Anurag");
        printBox(strItem);
    }

    // Wildcard
    private static void printBox(GenericBox<?> box) {
        System.out.println("This box contains: " + box.getContent());
    }
}

// Generic Class
class GenericBox<T> {

    private T content;

    public GenericBox(T content) {
        this.content = content;
    }

    // Generic Method
    public T getContent() {
        return this.content;
    }
}