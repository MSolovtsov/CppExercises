#include <iostream>
#include <boost/asio.hpp>

int main() {

    boost::asio::io_context io;     // Буст контекст операции ввода-вывода
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5)); // Таймер и время из chrono
    t.wait();
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
