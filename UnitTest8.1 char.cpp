#include "pch.h"
#include "CppUnitTest.h"
#pragma warning(disable : 4996)
#pragma warning(disable : 4603)
#include <cstring>
#include "C:\Users\USSER\Desktop\лаби\ап 8.1 char\ап 8.1 char\ап 8.1 char.cpp"   

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTestWhileChar)
    {
    public:

        // 1. Порожній рядок та рядок без "while"
        TEST_METHOD(TestNoWhile)
        {
            char t[101];

            Assert::AreEqual(0, Count(""));
            Assert::AreEqual(0, Count("hello world"));
            Assert::AreEqual(0, Count("whil whle"));

            Assert::AreEqual("", Change("", t));
            Assert::AreEqual("hello world", Change("hello world", t));
        }

        // 2. Одна група "while"
        TEST_METHOD(TestOneWhile)
        {
            char t[101];

            Assert::AreEqual(1, Count("while"));
            Assert::AreEqual(1, Count("awhileb"));

            Assert::AreEqual("***", Change("while", t));
            Assert::AreEqual("a***b", Change("awhileb", t));
        }

        // 3. Кілька груп "while"
        TEST_METHOD(TestSeveralWhile)
        {
            char t[101];

            Assert::AreEqual(2, Count("while x while"));
            Assert::AreEqual(3, Count("while1while2while"));

            Assert::AreEqual("*** x ***", Change("while x while", t));
            Assert::AreEqual("***1***2***", Change("while1while2while", t));
        }

        // 4. Крайні випадки для strstr / strncat
        TEST_METHOD(TestEdgeCases)
        {
            char t[101];

            // групи впритул
            Assert::AreEqual(2, Count("whilewhile"));
            Assert::AreEqual("******", Change("whilewhile", t));

            // неповна група перед повною
            Assert::AreEqual(1, Count("whilwhile"));
            Assert::AreEqual("whil***", Change("whilwhile", t));

            // група на початку та текст після неї
            Assert::AreEqual("***abc", Change("whileabc", t));

            // група в кінці, текст перед нею
            Assert::AreEqual("abc***", Change("abcwhile", t));

            // великі літери не рахуються
            Assert::AreEqual(0, Count("WHILE"));
            Assert::AreEqual("WHILE", Change("WHILE", t));
        }
    };
}