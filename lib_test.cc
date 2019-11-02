#include "lib.cc"

#include <gtest/gtest.h>

TEST(AddFileTest, TestFiles)
{
    inverted_index expectedResult = {{"1:",{"banana_recipe.txt"}},{"2:",{"banana_recipe.txt"}},{"Peel",{"banana_recipe.txt"}},{"Retrieve",{"banana_recipe.txt"}},{"Step",{"banana_recipe.txt"}},{"To",{"banana_recipe.txt"}},{"a",{"banana_recipe.txt"}},{"banana",{"banana_recipe.txt"}},{"banana.",{"banana_recipe.txt"}},{"banana:",{"banana_recipe.txt"}},{"from",{"banana_recipe.txt"}},{"grocery",{"banana_recipe.txt"}},{"prepare",{"banana_recipe.txt"}},{"store.",{"banana_recipe.txt"}}};
    string testFileName = "banana_recipe.txt";

    ASSERT_EQ(expectedResult, addFile(testFileName));
}

TEST(AddFileTest, StemmedTestFiles)
{
    inverted_index expectedResult = {{"1:",{"banana_recipe.txt"}},{"2:",{"banana_recipe.txt"}},{"Peel",{"banana_recipe.txt"}},{"Retriev",{"banana_recipe.txt"}},{"Step",{"banana_recipe.txt"}},{"To",{"banana_recipe.txt"}},{"a",{"banana_recipe.txt"}},{"banana",{"banana_recipe.txt"}},{"banana.",{"banana_recipe.txt"}},{"banana:",{"banana_recipe.txt"}},{"from",{"banana_recipe.txt"}},{"groceri",{"banana_recipe.txt"}},{"prepar",{"banana_recipe.txt"}},{"store.",{"banana_recipe.txt"}}};
    string testFileName = "banana_recipe.txt";

    ASSERT_EQ(expectedResult, addFile(testFileName, true));
}

TEST(SearchTermTest, TestTermsAndIndices)
{
    inverted_index testIndex = {{"1:",{"banana_recipe.txt"}},{"2:",{"banana_recipe.txt"}},{"Fish.",{"story_of_a_fish.txt"}},{"He",{"story_of_a_fish.txt"}},{"Peel",{"banana_recipe.txt"}},{"Retrieve",{"banana_recipe.txt"}},{"Step",{"banana_recipe.txt"}},{"There",{"story_of_a_fish.txt"}},{"To",{"banana_recipe.txt"}},{"a",{"banana_recipe.txt","story_of_a_fish.txt"}},{"around",{"story_of_a_fish.txt"}},{"banana",{"banana_recipe.txt"}},{"banana.",{"banana_recipe.txt"}},{"banana:",{"banana_recipe.txt"}},{"bit.",{"story_of_a_fish.txt"}},{"fish",{"story_of_a_fish.txt"}},{"from",{"banana_recipe.txt"}},{"grocery",{"banana_recipe.txt"}},{"named",{"story_of_a_fish.txt"}},{"prepare",{"banana_recipe.txt"}},{"store.",{"banana_recipe.txt"}},{"swam",{"story_of_a_fish.txt"}},{"was",{"story_of_a_fish.txt"}}};
    string testTerm = "banana";
    vector<string> expectedResult = {"banana_recipe.txt"};

    ASSERT_EQ(expectedResult, searchTerm(testTerm, testIndex));

    testTerm = "fish";
    expectedResult = {"story_of_a_fish.txt"};

    ASSERT_EQ(expectedResult, searchTerm(testTerm, testIndex));

    testTerm = "a";
    expectedResult = {"banana_recipe.txt", "story_of_a_fish.txt"};

    ASSERT_EQ(expectedResult, searchTerm(testTerm, testIndex));
}

TEST(MergeIndicesTest, TestIndices)
{
    inverted_index a = {{"hi", {"a", "b"}}};
    inverted_index b = {{"oh hey", {"c", "d"}}};
    inverted_index expectedResult = {{"hi", {"a", "b"}}, {"oh hey", {"c", "d"}}};

    ASSERT_EQ(expectedResult, mergeIndices(a, b));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
