#ifndef BONES_VECTOR2_H
#define BONES_VECTOR2_H

namespace Bones {
    
    template<typename T>
    class Vector2 {
    public:
        T x;
        T y;
        
        Vector2();
        Vector2(T x, T y);
    };
    
    // TODO: Define operators for vectors
    
    // Define common types of Vector2
    typedef Vector2<int> Vector2i;
    typedef Vector2<float> Vector2f;
    
}

#endif