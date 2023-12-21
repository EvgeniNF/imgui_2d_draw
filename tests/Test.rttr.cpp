#include <gtest/gtest.h>

#include <rttr/registration>
#include <rttr/type>
#include <rttr/variant.h>

struct TestStruct
{
    uint64_t    value1;
    float       value2;
};

RTTR_REGISTRATION
{
    rttr::registration::class_<TestStruct>("TestStruct")
                .constructor<>()
                .property("value1", &TestStruct::value1)
                .property("value2", &TestStruct::value2);
}

TEST(RTTR, registration)
{
    rttr::variant variant;
    {
        variant = TestStruct {12, 0.32f};
    }
    ASSERT_TRUE(variant.is_valid());

    const auto type = variant.get_type();
    ASSERT_EQ(type.get_name(), "TestStruct");

    {
        const auto& props = type.get_properties();
        auto it = props.cbegin();
        ASSERT_EQ(it->get_name(), "value1");
        ++it;
        ASSERT_EQ(it->get_name(), "value2");
    }
}

