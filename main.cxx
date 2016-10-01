#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

std::string const INPUT = "myfunc arg1 arg2\n";

void
get_next_word(std::string const& bytes, std::string *const p_buffer)
{
  auto &buffer = *p_buffer;
  for (auto c : bytes) {
    if (' ' == c) {
      break;
    }
    buffer += c;
  }
}

enum class token
{
  START_OF_FILE,
  START_OF_LINE,
  FUNCTION_NAME,
  IDENTIFIER,
  VAR,
  END_OF_LINE, // maybe not necessary??
  UNKNOWN
};

using lookup_table = std::map<token, char const*>;

lookup_table const TOKEN_MAP {
  { token::FUNCTION_NAME, "FUNCTION_NAME"},
  { token::START_OF_FILE, "START_OF_FILE"},
  { token::START_OF_LINE, "START_OF_LINE"},
  { token::UNKNOWN, "UNKNOWN"}
};

auto
get_token_from_word(token const prev_token, std::string const& word)
{
  std::pair<std::string, token> result;
  switch (prev_token)
  {
    case token::START_OF_FILE:
      // Ok for now, we'll assume we're defining a function.
      result = std::make_pair(word, token::FUNCTION_NAME);
      break;
    default:
      result = std::make_pair(word, token::UNKNOWN);
  }
  return result;
}

int
main(int argc, char **argv)
{
  token tok{token::START_OF_FILE};
  std::string buffer;
  get_next_word(INPUT, &buffer);

  auto const tp = get_token_from_word(tok, buffer);
  std::cout << "Token list:\n";
  std::cout << TOKEN_MAP.at(tp.second) << "\n";

  return EXIT_SUCCESS;
}
