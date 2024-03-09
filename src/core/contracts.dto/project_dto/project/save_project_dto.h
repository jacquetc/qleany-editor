// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include <QObject>
#include <QString>

namespace QleanyEditor::Contracts::DTO::Project
{
using namespace Qt::Literals::StringLiterals;

class SaveProjectDTO
{
    Q_GADGET

    Q_PROPERTY(QString fileName READ fileName WRITE setFileName)

public:
    struct MetaData {
        bool fileNameSet = false;
        bool getSet(const QString &fieldName) const
        {
            if (fieldName == "fileName"_L1) {
                return fileNameSet;
            }
            return false;
        }

        bool areDetailsSet() const
        {
            return false;
        }
    };

    SaveProjectDTO()
        : m_fileName(QString())
    {
    }

    ~SaveProjectDTO()
    {
    }

    SaveProjectDTO(const QString &fileName)
        : m_fileName(fileName)
    {
    }

    SaveProjectDTO(const SaveProjectDTO &other)
        : m_metaData(other.m_metaData)
        , m_fileName(other.m_fileName)
    {
    }

    SaveProjectDTO &operator=(const SaveProjectDTO &other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_fileName = other.m_fileName;
        }
        return *this;
    }

    SaveProjectDTO &operator=(const SaveProjectDTO &&other)
    {
        if (this != &other) {
            m_metaData = other.m_metaData;
            m_fileName = other.m_fileName;
        }
        return *this;
    }

    SaveProjectDTO &mergeWith(const SaveProjectDTO &other)
    {
        if (this != &other) {
            if (other.m_metaData.fileNameSet) {
                m_fileName = other.m_fileName;
                m_metaData.fileNameSet = true;
            }
        }
        return *this;
    }

    // import operator
    SaveProjectDTO &operator<<(const SaveProjectDTO &other)
    {
        return mergeWith(other);
    }

    friend bool operator==(const SaveProjectDTO &lhs, const SaveProjectDTO &rhs);

    friend uint qHash(const SaveProjectDTO &dto, uint seed) noexcept;

    // ------ fileName : -----

    QString fileName() const
    {
        return m_fileName;
    }

    void setFileName(const QString &fileName)
    {
        m_fileName = fileName;
        m_metaData.fileNameSet = true;
    }

    MetaData metaData() const
    {
        return m_metaData;
    }

private:
    MetaData m_metaData;

    QString m_fileName;
};

inline bool operator==(const SaveProjectDTO &lhs, const SaveProjectDTO &rhs)
{
    return lhs.m_fileName == rhs.m_fileName;
}

inline uint qHash(const SaveProjectDTO &dto, uint seed = 0) noexcept
{ // Seed the hash with the parent class's hash
    uint hash = 0;

    // Combine with this class's properties
    hash ^= ::qHash(dto.m_fileName, seed);

    return hash;
}

} // namespace QleanyEditor::Contracts::DTO::Project
Q_DECLARE_METATYPE(QleanyEditor::Contracts::DTO::Project::SaveProjectDTO)