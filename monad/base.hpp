#include<type_traits>
template <class fn>
class function_reference_wrapper {
public:
	// types
	using type = fn;

	// construct/copy/destroy
	template <class U, class = decltype(
	detail::FUN<T>(std::declval<U>()),
	std::enable_if_t<!std::is_same_v<reference_wrapper, std::remove_cvref_t<U>>>()
	)>
	constexpr reference_wrapper(U&& u) noexcept(noexcept(detail::FUN<T>(std::forward<U>(u))))
	: _ptr(std::addressof(detail::FUN<T>(std::forward<U>(u)))) {}
	reference_wrapper(const reference_wrapper&) noexcept = default;

	// assignment
	reference_wrapper& operator=(const reference_wrapper& x) noexcept = default;

	template< class... ArgTypes >
	constexpr std::invoke_result_t<T&, ArgTypes...>
	operator() ( ArgTypes&&... args ) const {
	return std::invoke(get(), std::forward<ArgTypes>(args)...);
	}
private:
	fn* ptr;
};

template<typename fn>
auto fmpa(fn&& Fn){
	std::decay_t<fn>
}
