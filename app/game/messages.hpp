#ifndef MESSAGES_HPP
#define MESSAGES_HPP

namespace message
{
    enum type
    {
        test
    };

    struct msgType
    {
        msgType(type ty)
            : m_type(ty)
        {;}

        type type() {return m_type;}
    private:
        type m_type;
    };

    /*struct position : msgType
    {

    };*/
}

#endif // MESSAGES_HPP
