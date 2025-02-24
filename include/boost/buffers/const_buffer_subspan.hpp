//
// Copyright (c) 2023 Vinnie Falco (vinnie.falco@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/cppalliance/buffers
//

#ifndef BOOST_BUFFERS_CONST_BUFFER_SUBSPAN_HPP
#define BOOST_BUFFERS_CONST_BUFFER_SUBSPAN_HPP

#include <boost/buffers/detail/config.hpp>
#include <boost/buffers/const_buffer.hpp>

namespace boost {
namespace buffers {

class const_buffer_span;

/** Holds a span of buffers that cannot be modified.

    Objects of this type meet the requirements
    of <em>ConstBufferSequence</em>.
*/
class const_buffer_subspan
{
    const_buffer const* p_ = nullptr;
    std::size_t n_ = 0;
    std::size_t p0_ = 0;
    std::size_t p1_ = 0;

    friend class const_buffer_span;

    inline
    const_buffer_subspan(
        const_buffer const* p,
        std::size_t n,
        std::size_t p0,
        std::size_t p1) noexcept;

public:
    /** The type of buffer.
    */
    using value_type = const_buffer;

    /** The type of iterators returned.
    */
    class const_iterator;

    /** Constructor.
    */
    const_buffer_subspan() = default;

    /** Constructor.
    */
    BOOST_BUFFERS_DECL
    const_buffer_subspan(
        const_buffer const* p,
        std::size_t n) noexcept;

    /** Constructor.
    */
    inline
    explicit
    const_buffer_subspan(
        const_buffer_span const& s) noexcept;

    /** Constructor.
    */
    const_buffer_subspan(
        const_buffer_subspan const&) = default;

    /** Assignment.
    */
    const_buffer_subspan& operator=(
        const_buffer_subspan const&) = default;

    /** Return an iterator to the beginning.
    */
    inline
    const_iterator
    begin() const noexcept;

    /** Return an iterator to the end.
    */
    inline
    const_iterator
    end() const noexcept;

    friend
    const_buffer_subspan
    tag_invoke(
        prefix_tag const&,
        const_buffer_subspan const& s,
        std::size_t n) noexcept
    {
        return s.prefix_impl(n);
    }

    friend
    const_buffer_subspan
    tag_invoke(
        suffix_tag const&,
        const_buffer_subspan const& s,
        std::size_t n) noexcept
    {
        return s.suffix_impl(n);
    }

private:
    BOOST_BUFFERS_DECL
    const_buffer_subspan
    prefix_impl(std::size_t n) const noexcept;

    BOOST_BUFFERS_DECL
    const_buffer_subspan
    suffix_impl(std::size_t n) const noexcept;
};

} // buffers
} // boost

#include <boost/buffers/impl/const_buffer_subspan.hpp>

#endif
