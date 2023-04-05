/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2023/01/10 18:15:14 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "utils.hpp"
# include "reverse_iterator.hpp"
# include "RandomAccessIterator.hpp"

// https://www.stroustrup.com/except.pdf
// https://stackoverflow.com/questions/31358804/whats-the-advantage-of-using-stdallocator-instead-of-new-in-c

namespace ft
{
	template< typename T, class A = std::allocator<T> >
	class Vector {

		public:

			// --------------- MEMBER TYPES ---------------

			typedef T												value_type;
			typedef A												allocator_type;
			typedef size_t											size_type;
			typedef std::ptrdiff_t									difference_type;
			typedef value_type&										reference;
			typedef const value_type&								const_reference;
			typedef typename A::pointer								pointer;
			typedef typename A::const_pointer						const_pointer;
			
			// https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits

			typedef ft::RandomAccessIterator<T>						iterator;
			typedef const iterator									const_iterator;
			
			typedef ft::reverse_iterator< iterator >				reverse_iterator;
			typedef const ft::reverse_iterator< const_iterator >	const_reverse_iterator;

			// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
		
			// https://stackoverflow.com/questions/2509499/how-to-use-stdallocator-in-my-own-container-class
		
			// Default Constructor
			Vector<T>( void )
			: _v(NULL), _capacity(0), _current(0)
			{
				return;
			}

			// Parametric Constructor
			Vector<T>( const unsigned int n )
			: _v(NULL), _capacity(n), _current(0)
			{
				_v = _allocator.allocate(_capacity, 0);
				
				return;
			}

			// Copy Constructor
			Vector<T>( Vector<T> const & src )
			: _v(NULL), _capacity(src._capacity), _current(src._current)
			{
				_v = _allocator.allocate(_capacity, 0);
				assign(src.begin(), src.end());

				return;
			}
		
			// Destructor
			~Vector<T>( void )
			{
				if (_v)
				{
					for (size_type idx=0; idx<_current; ++idx)
					{
						_allocator.destroy(&_v[idx]);
					}
					_allocator.deallocate(_v, _capacity);
				}
				
				return;
			}
		
			// --------------- OPERATOR OVERLOADS ---------------
		
			// Copy Assignment Operator Overload
			Vector<T> &	operator=(const Vector<T> & rhs)
			{
				if (this != &rhs)
				{
					for (size_type idx=0; idx<_current; ++idx)
					{
						_allocator.destroy(_v[idx]);
					}
					_allocator.deallocate(_v, _capacity);

					_capacity = rhs._capacity;
					_v = _allocator.allocate(_capacity, 0);
					assign(rhs.begin(), rhs.end());
				}

				return (*this);
			}

			// --------------- MEMBER FUNCTIONS ---------------
			
			// === ASSIGN ===

			void	assign( size_type count, const_reference value )
			{
				if (_current + count > _capacity)
				{
					resize(_capacity * 2);
				}
				
				for (size_type idx=0; idx<count; ++idx)
				{
					(*this)[idx] = value;
					++_current;
				}
			}
		
			template< class InputIt >
			void	assign( InputIt first, InputIt last )
			{

				size_type	count = 0;
				
				for (InputIt ite = first; ite != last; ++ite)
				{
					++count;
				}

				if (_current + count > _capacity)
				{
					resize(_capacity * 2);
				}

				size_type	idx;

				idx = 0;
				for (InputIt ite=first; ite<last; ++ite)
				{
					(*this)[idx++] = ite;
					++_current;
				}
				_current = idx;
			}

			// === GET_ALLOCATOR ===
			
			allocator_type	get_allocator(void) const
			{
				return _allocator;
			}
			
			// --- Element access ---

			// === AT ===

			reference	at(size_type idx)
			{
				return (*this)[idx];
			}
			
			const_reference at( size_type idx ) const
			{
				return (*this)[idx];
			}

			// === [] ===

			reference	operator[](size_type idx)
			{
				if (_v == NULL || idx >= _capacity)
				{
					throw std::out_of_range("Index out of range");
				}

				return _v[idx];
			}
			
			const_reference	operator[](size_type idx) const
			{
				if (_v == NULL || idx >= _capacity)
				{
					throw std::out_of_range("Index out of range");
				}

				return _v[idx];
			}

			// === FRONT ===

			reference	front(void)
			{
				return (*this)[0];
			}

			const_reference	front(void) const
			{
				return (*this)[0];
			}
			
			// === BACK ===
			
			reference	back(void)
			{
				return (*this)[_current - 1];
			}
			
			const_reference	back(void) const
			{
				return (*this)[_current - 1];
			}
	
			// === DATA ===
			
			value_type*	data(void)
			{
				return _v;
			}

			const value_type*	data(void) const
			{
				return _v;
			}

			// --- Iterators ---

			// === BEGIN ===
			
			iterator	begin(void)
			{
				return iterator(_v); 
			}
		
			const_iterator	begin(void) const
			{
				return const_iterator(_v); 
			}
			
			// === END ===
			
			iterator	end(void)
			{
				return iterator(_v + _capacity); 
			}

			const_iterator	end(void) const
			{
				return const_iterator(_v + _capacity); 
			}

			// === RBEGIN ===
			
			reverse_iterator	rbegin(void)
			{
				return reverse_iterator(_v); 
			}
			
			// === REND ===
			
			reverse_iterator	rend(void)
			{
				return reverse_iterator(_v + _capacity); 
			}

			// --- Capacity ---

			// === EMPTY ===

			bool	empty(void) const
			{
				return (begin() == end());	
			}
			
			// === SIZE ===

			size_type	size(void) const
			{
				return (std::distance(begin(), end()));
			}
			
			// === MAX SIZE ===
			
			size_type	max_size(void) const
			{
				return (std::numeric_limits<size_type>::max() / sizeof(T));
			}
			
			// === RESERVE ===
			
			void	reserve( size_type new_cap )
			{
				if (new_cap > max_size())
				{
					throw std::length_error("Capacity exceeds max size");
				}
				
				pointer			new_v;
	
				new_v = _allocator.allocate(new_cap, 0);
				if (!new_v)
				{
					throw std::bad_alloc();
				}
				
				for (size_type idx=0; idx<_current; ++idx)
				{
					_allocator.construct(new_v[idx], _v[idx]);
					_allocator.destroy(_v[idx]);
				}
				_allocator.deallocate(_v, _capacity);
				
				_v = new_v;
				_capacity = new_cap;
			}
			
			// === CAPACITY ===
			
			size_type capacity(void) const
			{
				return _capacity;
			}

			// --- Modifiers ---

			// === CLEAR ===
			
			void	clear(void)
			{
				for (size_type idx=0; idx<_current; ++idx)
				{
					_allocator.destroy(_v[idx]);
				}
				_current = 0;
			}
			
			// === INSERT ===
			
			iterator	insert( const_iterator pos, const T& value )
			{
				size_type	idx = pos - begin();

				if (idx > size())
				{
					throw std::out_of_range("Index out of range");
				}
				
				if (size() + 1 >= _capacity)
				{
					resize(_capacity * 2);
				}

				for (size_type i = _current + 1; i > idx; --i)
				{
					(*this)[i] = (*this)[i - 1];
				}

				(*this)[idx] = value;
				++_current;
				
				return &(*this)[idx];
			}

			iterator insert( const_iterator pos, size_type count, const T& value )
			{
				size_type	idx = pos - begin();

				if (idx > size())
				{
					throw std::out_of_range("Index out of range");
				}
				
				while (size() + count >= _capacity)
				{
					resize(_capacity * 2);
				}

				for (size_type i = _current + count; i > idx; --i)
				{
					(*this)[i] = (*this)[i - 1];
				}

				for (size_type i = 0; i < count; ++i)
				{
					(*this)[idx++] = value;
				}
				_current += count;
				
				return &(*this)[idx];
			}

			template< class InputIt >
			iterator insert( const_iterator pos, InputIt first, InputIt last )
			{
				size_type	idx = pos - begin();
				size_type	count = 0;

				if (idx > size())
				{
					throw std::out_of_range("Index out of range");
				}
				
				for (InputIt ite = first; ite != last; ++ite)
				{
					++count;
				}
				while (size() + count >= _capacity)
				{
					resize(_capacity * 2);
				}

				for (size_type i = _current + count; i > idx; --i)
				{
					(*this)[i] = (*this)[i - 1];
				}

				for (InputIt ite = first; ite != last; ++ite)
				{
					(*this)[idx++] = *ite;
				}
				_current += count;
				
				return &(*this)[idx];
			}

			// === ERASE ===
			
			iterator	erase( iterator pos )
			{
				size_type	idx = pos - begin();

				if (idx > size())
				{
					throw std::out_of_range("Index out of range");
				}
				
				for (size_type i = _current; i >= idx; --i)
				{
					(*this)[i] = (*this)[i + 1];
				}
				--_current;
				
				return &(*this)[idx];
			}

			iterator	erase( iterator first, iterator last )
			{
				size_type	idx = first - begin();
				size_type	count = 0;

				if (idx > size())
				{
					throw std::out_of_range("Index out of range");
				}
				
				for (iterator ite = first; ite != last; ++ite)
				{
					++count;
				}
				
				for (size_type i = _current; i >= idx - count; --i)
				{
					(*this)[i] = (*this)[i + 1];
				}
				
				_current -= count;
				
				return &(*this)[idx];
			}
			
			// === PUSH BACK ===
			
			void	push_back( const T& value )
			{
				insert(_current, value);
			}

			// === POP BACK ===
			
			void	pop_back(void)
			{
				erase(_current - 1);
			}
		
			// === RESIZE ===
			
			void	resize( size_type count )
			{
					pointer			new_v;
		
					new_v = _allocator.allocate(count, 0);
					if (!new_v)
					{
						throw std::bad_alloc();
					}
					
					if (_current > count)
					{
						_current = count;
					}
					
					for (size_type idx=0; idx<_current; ++idx)
					{
						_allocator.construct(&new_v[idx], _v[idx]);
						_allocator.destroy(&_v[idx]);
					}
					_allocator.deallocate(_v, _capacity);
					
					_v = new_v;
					_capacity = count;
			}
		
			// === SWAP ===
			
			void	swap( Vector<T>& other )
			{
				pointer			tmp_v;
				size_type		tmp_capacity;
				size_type		tmp_current;
				A				tmp_allocator;
				
				tmp_v = _v;
				tmp_capacity = _capacity;
				tmp_current = _current;
				tmp_allocator = _allocator;

				_v = other._v;
				other._v = tmp_v;

				_capacity = other._capacity;
				other._capacity = tmp_capacity;

				_current = other._current;
				other._current = tmp_current;

				_allocator = other._allocator;
				other._allocator = tmp_allocator;
			}

			// --------------- NON-MEMBER FUNCTIONS ---------------
			
			bool	operator==(const Vector<T> & rhs) const
			{
				return (ft::equal< Vector<T> >(begin(), end(), rhs.begin()));
			}
			
			bool	operator!=(const Vector<T> & rhs) const
			{
				return (!ft::equal< Vector<T> >(begin(), end(), rhs.begin()));
			}
			
			bool	operator<(const Vector<T> & rhs) const
			{
				return (std::less< Vector<T> >(begin(), end(), rhs.begin()));
			}
			
			bool	operator<=(const Vector<T> & rhs) const
			{
				return (std::less_equal< Vector<T> >(begin(), end(), rhs.begin()));
			}
			
			bool	operator>(const Vector<T> & rhs) const
			{
				return (std::greater< Vector<T> >(begin(), end(), rhs.begin()));
			}
			
			bool	operator>=(const Vector<T> & rhs) const
			{
				return (std::greater_equal< Vector<T> >(begin(), end(), rhs.begin()));
			}
			
		private:

			pointer			_v;
			size_type		_capacity;
			size_type		_current;
			A				_allocator;
		
	};
};

#endif
