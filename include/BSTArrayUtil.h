#pragma once

#include <algorithm>

using namespace RE;

namespace BSTArrayUtil {
    template <class T>
    uint32_t GetID(T a) {
        if (!a)
            return 0;
        else
            return a->formID;
    }

    template <class T>
    bool Compare(T a, T b) {
        return GetID(a) < GetID(b);
    }

    template <class T>
    bool Equals(T a, T b) {
        return !(Compare(a, b) || Compare(b, a));
    }

    template <class T>
    bool IsIn(T* a, BSTArray<T*> B) {
        for (T* b : B)
            if (Equals(a, b))
                return true;
        return false;
    }

    template <class T>
    BSTArray<T*> Sort(BSTArray<T*> A) {
        std::sort(A.begin(), A.end(), Compare<T*>);
        return A;
    }

    template <class T>
    BSTArray<T*> ToSet(BSTArray<T*> A) {
        A = Sort(A);
        BSTArray<T*> set;
        for (int i = 0; i < A.size(); i++)
            if (set.size() == 0 || !Equals(set[set.size() - 1], A[i]))
                set.push_back(A[i]);
        return set;
    }

    template <class T>
    BSTArray<T*> Intersect(BSTArray<T*> A, BSTArray<T*> B) {
        BSTArray<T*> intersection;
        A = ToSet(A);
        B = ToSet(B);

        std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), intersection.begin(), Compare<T*>);
        return intersection;
    }
    
    template <class T>
    BSTArray<T*> Difference(BSTArray<T*> A, BSTArray<T*> B) {
        BSTArray<T*> difference;
        A = ToSet(A);
        B = ToSet(B);
        for (T* a : A)
            if (!IsIn(a, B))
                difference.push_back(a);
        return difference;
    }

    template <class T>
    BSTArray<T*> Filter(BSTArray<T*> A, std::function<bool (T*)> filter) {
        BSTArray<T*> result;
        for (T* item : A)
            if (filter(item))
                result.push_back(item);
        return result;
    }

    template <class T>
    BSTArray<T*> FilterByModID(BSTArray<T*> A, T* form) {
        auto modID = [](T* b) {
            return b ? b->formID >> 6 : 0;
        };
        auto filter = [=](T* b) {
            return modID(form) == modID(b);
        };
        return Filter(A, filter);
    }

    template <class T>
    BSTArray<T*> FilterByValue(BSTArray<T*> A, std::function<uint32_t (T*)> func, uint32_t value) {
        BSTArray<T*> result;
        for (T* item : A)
            if (func(item) == value)
                result.push_back(item);
        return result;
    }

    template <typename Function, typename... Arguments>
    auto PartialApplication(Function func, Arguments... args) {
        return [=](auto... rest) {
            return func(args..., rest...);
        };
    }
}