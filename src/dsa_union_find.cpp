#include "dsa_union_find.hpp"

namespace dsa_practice
{
  UnionFind::UnionFind(size_t size)
  {
    mParent.resize(size, 0);
    for (size_t idx = 0; idx < mParent.size(); idx++)
    {
      mParent[idx] = idx;
    }

    mRank.resize(size, 0);
  }

  int UnionFind::find(const int elmt)
  {
    if (mParent[elmt] != elmt)
    {
      mParent[elmt] = find(mParent[elmt]);
    }

    return mParent[elmt];
  }

  void UnionFind::unionSets(const int elmtA, const int elmtB)
  {
    int rootA = find(elmtA);
    int rootB = find(elmtB);

    // We have disjoint sets:
    if (rootA != rootB)
    {
      if (mRank[rootA] < mRank[rootB])
      {
        mParent[rootA] = rootB;
      }
      else if (mRank[rootA] > mRank[rootB])
      {
        mParent[rootB] = rootA;
      }
      // In this case: rootA and rootB have same height, but since we but B under A the resulting as
      // height + 1
      else
      {
        mParent[rootB] = rootA;
        mRank[rootA]++;
      }
    }
  }

} // namespace dsa_practice
