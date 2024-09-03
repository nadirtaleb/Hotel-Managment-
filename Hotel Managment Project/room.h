#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

class Room {
protected:
    int roomNo;
    bool availabilityArray[360];
public:
    Room(int no);
    virtual void print() const = 0;
    virtual ~Room();
    
    int getRoomNo() const;
    void setRoomNo(int no);
    bool* getAvailabilityArray();
    void setAvailabilityArray(const bool availability[]);
};

class StdRoom : public Room {
private:
    bool extraBed;
public:
    StdRoom(int no);
    bool getExtraBed() const;
    void setExtraBed(bool bed);
    void print() const override;
};

class DeluxRoom : public Room {
private:
    std::string view;
public:
    DeluxRoom(int no, const std::string& vw);
    std::string getView() const;
    void setView(const std::string& vw);
    void print() const override;
};

class Suite : public Room {
private:
    std::string suiteSize;
public:
    Suite(int no, const std::string& size);
    std::string getSuiteSize() const;
    void setSuiteSize(const std::string& size);
    void print() const override;
};

#endif
