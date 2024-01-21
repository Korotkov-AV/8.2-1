// 8.2-1.cpp :


#include <iostream>
#include <algorithm>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};


class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    Text* text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph : public DecoratedText {
public:
    explicit Paragraph(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed : public DecoratedText {
public:
    explicit Reversed(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const {
        std::string reversed_data = data;
        std::reverse(std::begin(reversed_data), std::end(reversed_data));
        text_->render(reversed_data);
    }
};

class Link : public DecoratedText {
public:
    explicit Link(Text* text) : DecoratedText(text) {}

    void render(const std::string& link, const std::string& head)  const {
        std::cout << "<a href=";
        text_->render(link);
        std::cout << ">";
        text_->render(head);
        std::cout << "</a>";
    }

};

int main() {
    auto text_block = new Reversed(new Text());
    text_block->render("Hello world");

    std::cout << std::endl;

    auto text_block2 = new Link(new Text());
    text_block2->render("netology.ru", "Hello world");
}
