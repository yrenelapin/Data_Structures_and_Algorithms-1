import operator


def bidProperty(PropertyList, TenderList):

    history = []
    TenderList.sort(key=operator.attrgetter('bidPrice'), reverse=True)
    result = []
    for item in TenderList:

        for prop_item in PropertyList:

            if ((item.propertyType.lower() == prop_item.property_type.lower())
                and (item.bidPrice >= prop_item.property_value) and
                    (item.bidPrice <= prop_item.max_bid_price)):

                # Check if its already placed
                present = 0
                for i in history:
                    if (i == item.propertyType):
                        present = 1
                        break

                # Not present earlier
                if (present == 0):
                    result.append(item.buyerName)
                    history.append(item.propertyType)

                PropertyList.remove(prop_item)
                break

    if (len(result) == 0):
        return None
    else:
        return result


class Property:
    def __init__(self, property_type, property_value, max_bid_price):
        self.property_type = property_type
        self.property_value = property_value
        self.max_bid_price = max_bid_price


class Tender:
    def __init__(self, buyerName, propertyType, bidPrice):
        self.buyerName = buyerName
        self.propertyType = propertyType
        self.bidPrice = bidPrice


PropertyList = []
n = eval(input())
for i in range(n):
    property_type = input()
    property_value = eval(input())
    max_bid_price = eval(input())
    x = Property(property_type, property_value, max_bid_price)
    PropertyList.append(x)


TenderList = []
n = eval(input())
for i in range(n):
    buyerName = input()
    propertyType = input()
    bidPrice = eval(input())
    x = Tender(buyerName, propertyType, bidPrice)
    TenderList.append(x)

final = bidProperty(PropertyList, TenderList)

if (final == None):
    print("Property Not found")
else:
    for i in final:
        print(i)

for each in PropertyList:
    print(each.property_type)
