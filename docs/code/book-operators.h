class Book {
    ...
public:
    ...
    friend std::ostream &operator<<(std::ostream &os, const Book &book);

    friend std::ofstream &operator<<(std::ofstream &out, const Book &book);
    ...
};