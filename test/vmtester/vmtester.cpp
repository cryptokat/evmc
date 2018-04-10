// EVMC -- Ethereum Client-VM Connector API
// Copyright 2018 Pawel Bylica.
// Licensed under the MIT License. See the LICENSE file.

#include <boost/dll/import.hpp> // for import_alias
#include <boost/make_shared.hpp>
#include <boost/function.hpp>
#include <iostream>

namespace dll = boost::dll;

std::size_t
search_for_symbols(const std::vector<boost::filesystem::path> &plugins) {
  std::size_t plugins_found = 0;

  for (std::size_t i = 0; i < plugins.size(); ++i) {
    std::cout << "Loading plugin: " << plugins[i] << '\n';
    dll::shared_library lib(plugins[i], dll::load_mode::append_decorations);
    if (!lib.has("create_plugin")) {
      // no such symbol
      continue;
    }
  }

  return plugins_found;
}

int main()
{
    return 0;
}
