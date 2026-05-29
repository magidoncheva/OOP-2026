#ifndef __FISH_H__
#define __FISH_H__

class Fish: virtual public Animal {
    public:
        Animal* duplicate() const {
            return new Fish(*this);
        }
};

#endif // __FISH_H__