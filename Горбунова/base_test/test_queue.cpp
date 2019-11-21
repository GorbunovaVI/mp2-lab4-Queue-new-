#include "queue.h"
#include <gtest.h>

TEST(Queue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(Queue v(5));
}

TEST(Queue, cant_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(Queue v(-5));
}

TEST(Queue, cant_create_queue_with_zero_length)
{
	ASSERT_ANY_THROW(Queue v(0));
}

TEST(Queue, cant_create_too_large_queue)
{
	ASSERT_ANY_THROW(Queue v(MaxSize + 100));
}

TEST(Queue, cant_put_to_full_queue)
{
	Queue v(2);
	v.put(1);
	v.put(2);
	ASSERT_ANY_THROW(v.put(4));
}

TEST(Queue, cant_top_of_clear_queue)
{
	Queue v(2);
	ASSERT_ANY_THROW(v.top());
}

TEST(Queue, can_top_of_queue)
{
	Queue v(2);
	v.put(1);
	ASSERT_NO_THROW(v.top());
}

TEST(Queue, can_top_of_queue_one)
{
	Queue v(5);
	v.put(4);
	EXPECT_EQ(4, v.top());
}

TEST(Queue, can_top_of_queue_two)
{
	Queue v(5);
	v.put(4);
	v.put(7);
	EXPECT_EQ(4, v.top());
}

TEST(Queue, can_top_of_queue_three)
{
	Queue v(5);
	v.put(4);
	v.put(1);
	v.put(77);
	EXPECT_EQ(4, v.top());
}

TEST(Queue, can_top_twice_of_queue_three)
{
	Queue v(5);
	v.put(4);
	v.put(1);
	v.put(77);
	v.get();
	EXPECT_EQ(1, v.top());
}

TEST(Queue, cant_get_of_clear_queue)
{
	Queue v(2);
	ASSERT_ANY_THROW(v.get());
}

TEST(Queue, can_get_of_queue)
{
	Queue v(2);
	v.put(1);
	ASSERT_NO_THROW(v.get());
}


TEST(Queue, IsEmpty_true_of_clear_queue)
{
	Queue v(2);
	ASSERT_TRUE(v.IsEmpty());
}

TEST(Queue, IsEmpty_false_of_any_queue)
{
	Queue v(2);
	v.put(4);
	ASSERT_FALSE(v.IsEmpty());
}

TEST(Queue, IsFull_true_of_full_queue)
{
	Queue v(2);
	v.put(4);
	v.put(4);
	ASSERT_TRUE(v.IsFull());
}

TEST(Queue, IsFull_false_of_clear_queue)
{
	Queue v(2);
	ASSERT_FALSE(v.IsFull());
}

TEST(Queue, IsFull_false_of_any_queue)
{
	Queue v(2);
	v.put(4);
	ASSERT_FALSE(v.IsFull());
}
