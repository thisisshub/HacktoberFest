#include <iostream>
#include <string>

namespace xor_cipher {
    class XOR {
        public:
        static std::string encrypt (const std::string &text, const int &key) {
            std::string encrypted_text = "";
            for (auto &c: text) {
                char encrypted_char = char(c ^ key);
                encrypted_text += encrypted_char;
            }
            return encrypted_text;
        }

        static std::string encrypt (const std::string &text, const std::string &key) {
            std::string encrypted_text = "";
            size_t key_len = key.length();
            for (int i = 0; i < text.length(); i++) {
                char encrypted_char = (char)(text.at(i) ^ key.at(i % key_len));
                encrypted_text += encrypted_char;
            }
            return encrypted_text;
        }
        
        static std::string decrypt (const std::string &text, const int &key) {
            std::string decrypted_text = "";
            for (auto &c : text) {
                char decrypted_char = char(c ^ key);
                decrypted_text += decrypted_char;
            }
            return decrypted_text;
        }

        static std::string decrypt (const std::string &text_in, const std::string &key) {
            std::string decrypted_text = "";
            std::string text = text_in;
            size_t key_len = key.length();

            if(text.rfind("0x", 0) == 0)
                text.erase(0, 2);

            for (int i = 0; i < text.length(); i++) {
                char decrypted_char = (char)(text.at(i) ^ key.at(i % key_len));
                decrypted_text += decrypted_char;
            }
            return decrypted_text;
        }
    };
}

void print_hex(const char *s)
{
  printf("0x");
  while(*s)
    printf("%02x", (unsigned int) *s++);
  printf("\n");
}

int main() {
    std::string plain = "hello world!!";
    std::string key   = "Alice and Bob";

    std::cout << "\"" + plain + "\" encrypted with key \"" + key + "\"" << std::endl;

    std::string encrypted = xor_cipher::XOR::encrypt(plain, key);

    print_hex(encrypted.c_str());

    std::string decrypted = xor_cipher::XOR::decrypt(encrypted, key);

    std::cout << "Decrypted with key \"" + key + "\": \"" + decrypted + "\"" << std::endl;

}