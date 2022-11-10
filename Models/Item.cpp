
#include <stdlib.h>
#include <string>

namespace Item {

  enum ItemType {
    Electronics,
    Appliances,
    Sport,
    NONE,

  };

    std::string TypeToString( ItemType type ) {
      switch ( type ) {
        case Electronics:
          return "Electronics";
        case Appliances:
          return "Appliances";
        case Sport:
          return "Sport";
        default:
          return "NULL";
      }
    }

  struct Item {
    std::string name;
    ItemType type;
    float unit_price;
    int count;

    std::string to_string(  ) {
      std::string r = "Item(";
      r += "Name="+this->name;
      r += ", Type"+TypeToString(this->type);
      r += ", Unit_Price="+std::to_string(this->unit_price);
      r += ", Count="+std::to_string(this->count)+")";
      return r;
    }

  };


  class ItemHandle {
    private:
    Item* MyItem;
    public:
    ItemHandle( std::string name="MISSING", ItemType type=ItemType::NONE, float unit_price=0, int count=0 ) {
      Item* h = (Item*) malloc(sizeof(Item));
      h->name = name;
      h->type = type;
      h->unit_price = unit_price;
      h->count = count;
      MyItem = h;
    }

    std::string to_string() {
      std::string r = "ItemHandle(MyItem="+MyItem->to_string()+")";
      return r;
    }

    void changeName( std::string newName ) {
      MyItem->name = newName;
    }

    void changeType( ItemType newType) {
      MyItem->type = newType;
    }

    void changeUnitPRice( float newPrice ) {
      MyItem->unit_price = newPrice;
    }

    void changeCount( int newCount ) {
      MyItem->count = newCount;
    }

    ~ItemHandle() {
      free(MyItem);
    }

  };
}