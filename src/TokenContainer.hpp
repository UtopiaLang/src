#pragma once

#include "fwddecl.hpp"

#include "Token.hpp"

#include <memory>

namespace Utopia
{
	class TokenContainer : public Token
	{
	public:
		std::unique_ptr<Token> left{};
		std::unique_ptr<Token> right{};

	protected:
		using Token::Token;

		explicit TokenContainer(TokenType type, TokenContainer&& b);

	public:
		[[nodiscard]] const SourceLocation& getLeftmostSourceLocation() const final;
	};
}
