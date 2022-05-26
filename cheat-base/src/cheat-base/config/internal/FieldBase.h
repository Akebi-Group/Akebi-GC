#pragma once

#include "FieldEntry.h"
#include "FieldSerialize.h"
#include <cheat-base/events/event.hpp>
#include <cheat-base/events/handlers/methodeventhandler.hpp>

namespace config::internal
{
	template<typename T>
	class FieldBase
	{
		using _FieldBaseT = FieldBase<T>;
	public:
		using _ValueType = T;

		explicit FieldBase() : p_Container(nullptr), FieldChangedEvent(m_FieldChangedEvent) {}

		explicit FieldBase(FieldSerialize<T>* serializeFieldPtr) : p_Container(serializeFieldPtr), FieldChangedEvent(m_FieldChangedEvent) 
		{ 
			p_Container->ChangedEvent += MY_METHOD_HANDLER(_FieldBaseT::OnFieldChanged);
		}

		explicit FieldBase(const std::shared_ptr<FieldSerialize<T>>& serializeField) : p_Container(serializeField), FieldChangedEvent(m_FieldChangedEvent) 
		{ 
			p_Container->ChangedEvent += MY_METHOD_HANDLER(_FieldBaseT::OnFieldChanged);
		}

		explicit FieldBase(const std::string friendlyName, const std::string name, const std::string section, T defaultValue, bool multiProfile = false)
			: p_Container(std::make_shared<FieldSerialize<T>>(friendlyName, name, section, defaultValue, multiProfile)), FieldChangedEvent(m_FieldChangedEvent) 
		{
			p_Container->ChangedEvent += MY_METHOD_HANDLER(_FieldBaseT::OnFieldChanged);
		}

		explicit FieldBase(const FieldBase<T>& field) : 
			p_Container(field.p_Container), 
			m_FieldChangedEvent(), FieldChangedEvent(m_FieldChangedEvent)
		{
			p_Container->ChangedEvent += MY_METHOD_HANDLER(FieldBase<T>::OnFieldChanged);
		}

		~FieldBase()
		{
			if (p_Container.get() != nullptr)
				p_Container->ChangedEvent -= MY_METHOD_HANDLER(FieldBase<T>::OnFieldChanged);
		}

		std::string name() const
		{
			return p_Container->GetName();
		}

		std::string friendName() const
		{
			return p_Container->GetFriendName();
		}

		std::string section() const
		{
			return p_Container->GetSection();
		}

		bool shared() const
		{
			return p_Container->IsShared();
		}

		T& value() const
		{
			return p_Container->m_Value;
		}

		T* pointer() const
		{
			return &p_Container->m_Value;
		}

		std::shared_ptr<internal::FieldEntry> entry() const
		{
			return std::static_pointer_cast<FieldEntry>(p_Container);
		}

		operator T& () const
		{
			return value();
		}

		operator T* () const
		{
			return pointer();
		}

		void FireChanged() const
		{
			p_Container->FireChanged();
		}

		void repos(const std::string& newSection, bool shared = false)
		{
			p_Container->Reposition(newSection, shared);
		}

		void move(const std::string& newSection, bool shared = false)
		{
			p_Container->Move(newSection, shared);
		}

		FieldBase<T>& operator=(const T& other)
		{
			p_Container->m_Value = other;
			p_Container->FireChanged();
			return *this;
		}

		FieldBase<T>& operator=(std::shared_ptr<FieldSerialize<T>>& other)
		{
			p_Container->ChangedEvent -= MY_METHOD_HANDLER(FieldBase<T>::OnFieldChanged);

			p_Container = other;
			p_Container->ChangedEvent += MY_METHOD_HANDLER(FieldBase<T>::OnFieldChanged);
			return *this;
		}

		FieldBase<T>& operator=(FieldSerialize<T>* other)
		{
			p_Container->ChangedEvent -= MY_METHOD_HANDLER(FieldBase<T>::OnFieldChanged);

			p_Container = std::make_shared<FieldSerialize<T>>(other);
			p_Container->ChangedEvent += MY_METHOD_HANDLER(FieldBase<T>::OnFieldChanged);
			return *this;
		}

		FieldBase<T>& operator=(const FieldBase<T>& other)
		{
			p_Container = other.p_Container;
			p_Container->ChangedEvent += MY_METHOD_HANDLER(FieldBase<T>::OnFieldChanged);
			return *this;
		}
		
		IEvent<T&>& FieldChangedEvent;

	protected:
		TEvent<T&> m_FieldChangedEvent;

		std::shared_ptr<FieldSerialize<T>> p_Container;
		void OnFieldChanged(FieldEntry* entry)
		{
			m_FieldChangedEvent(value());
		}

	};
}