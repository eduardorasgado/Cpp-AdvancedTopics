#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <cstdlib>

template <class T>
class EventBus
{
private:
    std::shared_ptr<std::vector< std::map <int, T > > > container;
    int numElements;
    std::map<int, T> lastElementInserted;
    int tolerance;
public:
    EventBus (int tolerance): tolerance{tolerance}
    {
        std::cout << "[BUS CREATED]" << std::endl;
        container = std::make_shared<std::vector<std::map<int, T>>>();
    } // Constructor
    ~EventBus() { std::cout << "[BUS DESTRUCTED]" << std::endl; } // destructor

    bool insertElement(const std::map<int, T> mapToInsert) const noexcept
    {
        // inserting new elements to event bus
        try {
            std::cout << "[INSERTING NEW DATA TO BUS EVENT]: " << mapToInsert.size() << std::endl;
            container->push_back(mapToInsert);
            std::cout << "[DATA INSERTED]" << std::endl;

        } catch (std::exception e) {
            std::cout << "[ERROR TRYING TO INSERT INTO BUS]" << std::endl;
            return false;
        }
        return true;
    }
};

typedef std::pair<int, std::string> pair;

template <typename T>
std::shared_ptr<EventBus<T>> createEventBus(
        std::shared_ptr<std::vector<std::map<int, T>>> container
) noexcept
{
    // creating the first data will be inserted
    for(int i = 0; i < 10; ++i)
    {
        auto content = std::map<int, T>();
        for(int j =0;j < 10;++j)
        {
            std::string converted = std::to_string(i);
            std::string objectSticked = " this is the number "+ converted;
            content.insert(pair(j, objectSticked));
        }
        container->push_back(content);
    }

    auto tolerance = 1000;
    // creating the firstEvent Bus
    auto EventBusReturned = std::make_shared<EventBus<T>>(tolerance);

    // all elements in container are maps and maps have their own elements
    for(auto& singlemap : *container)
    {
        //inserting elements in the event bus
        auto state = EventBusReturned->insertElement(singlemap);

        //auto state = true;
        for(auto& duple : singlemap)
        {
            // accessing element in the map
            std::cout << "elements: " << duple.first << ": " << duple.second << std::endl;
        }
        //std::cout << "this" << std::endl;
        if (!state)
        {
            //std::cout << "got so far" << std::endl;
            return NULL;
        }
    }
    // if everything is ok
    return EventBusReturned;
}

int main() {
    std::cout << "[ABSTRACT EVENT BUS]\n";

    auto firstEntry = std::make_shared<std::vector<std::map<int, std::string>>>();

    auto starterBus = createEventBus(firstEntry);

    // other practice

    auto myMap =std::make_shared<std::map<int, std::string>>();

    myMap->insert(std::pair<int, std::string>(1, "hola"));
    myMap->insert(std::pair<int, std::string>(2, "adios"));

    //std::map<int, std::string>::size_type i =0;

    for(auto& m : *myMap)
    {
        std::cout << "element: " << m.second << std::endl;
    }

    return 0;

}