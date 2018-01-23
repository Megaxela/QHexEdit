#include <gtest/gtest.h>
#include <QBuffer>
#include <document/gapbuffer.h>

static auto basic = QByteArray::fromHex("00112233445566778899AABBCCDDEEFF");

TEST(GapBuffer, Creation)
{
    QBuffer buffer;

    buffer.setData(basic);
    buffer.open(QBuffer::ReadOnly);

    GapBuffer gapBuffer(&buffer);

    ASSERT_EQ(gapBuffer.toByteArray(), basic);
}

TEST(GapBuffer, Insertion)
{
    for (auto i = 0; i < basic.size(); ++i)
    {
        auto copy = basic;

        QBuffer buffer;

        buffer.setData(basic);
        buffer.open(QBuffer::ReadOnly);

        GapBuffer gapBuffer(&buffer);

        // Inserting
        copy.insert(i, static_cast<char>(0xBB));
        gapBuffer.insert(static_cast<integer_t>(i), QByteArray("\xbb", 1));

        // Comparing
        ASSERT_EQ(copy, gapBuffer.toByteArray());
    }
}

TEST(GapBuffer, Replacing)
{
    const auto value = QByteArray("\xbb", 1);

    for (auto i = 0; i < basic.size(); ++i)
    {
        auto copy = basic;

        QBuffer buffer;

        buffer.setData(basic);
        buffer.open(QBuffer::ReadOnly);

        GapBuffer gapBuffer(&buffer);

        // Inserting
        copy.replace(i, 1, value);
        gapBuffer.replace(static_cast<integer_t>(i), value);

        // Comparing
        ASSERT_EQ(copy, gapBuffer.toByteArray());
    }
}


TEST(GapBuffer, InsertAndReplace)
{
    auto copy = basic;

    QBuffer buffer;

    buffer.setData(basic);
    buffer.open(QBuffer::ReadOnly);

    GapBuffer gapBuffer(&buffer);

    // Insertion
    copy.insert(1, static_cast<char>(0xAA));
    gapBuffer.insert(static_cast<integer_t>(1), QByteArray("\xAA", 1));

    // Replacing
    copy.replace(0, 1, QByteArray("\xbb", 1));
    gapBuffer.replace(static_cast<integer_t>(0), QByteArray("\xbb", 1));

    // Comparison
    ASSERT_EQ(copy, gapBuffer.toByteArray());
}