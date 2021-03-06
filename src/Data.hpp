#pragma once

#include "fwddecl.hpp"

#include <memory>
#include <string>

#include "DataType.hpp"

namespace Utopia
{
	class Data
	{
	public:
		const DataType type;

	protected:
		explicit Data(const DataType type);

	public:
		virtual ~Data();

		[[nodiscard]] static const char* getTypeName(const DataType type);
	private:
		[[nodiscard]] std::string getTypeErrorMessage(const DataType expected_type) const;
	public:
		void expectType(const DataType expected_type) const;
		void expectType(const DataType expected_type, const SourceLocation& loc) const;

		[[nodiscard]] virtual std::string toString() const = 0;
		[[nodiscard]] virtual std::string toCPP() const = 0;

		[[nodiscard]] static std::unique_ptr<Data> instantiateType(DataType type);

		[[nodiscard]] virtual std::unique_ptr<Data> copy() const = 0;

		[[nodiscard]] virtual bool equals(const Data& b) const;
	};
}
