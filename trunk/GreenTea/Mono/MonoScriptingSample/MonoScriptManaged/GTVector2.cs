using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.CompilerServices;

namespace GTEngineManaged
{
    public class GTVector2C
    {
        public GTVector2C(float x, float y)
        {
            this.x = x;
            this.y = y;
        }

        public float x;
        public float y;
    }

    public struct GTVector2
    {
        public float x;
        public float y;

        public GTVector2(float x, float y)
        {
            this.x = x;
            this.y = y;
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern void SetOffset(float offsetx, float offsety);
    }

    /*
    public struct GTVector2
    {
        public const float kEpsilon = 1E-05f;
        public float x;
        public float y;

        public GTVector2(float x, float y)
        {
            this.x = x;
            this.y = y;
        }

        public float this[int index]
        {
            get
            {
                switch (index)
                {
                    case 0:
                        return this.x;

                    case 1:
                        return this.y;
                }
                throw new IndexOutOfRangeException("Invalid GTVector2 index!");
            }
            set
            {
                switch (index)
                {
                    case 0:
                        this.x = value;
                        break;

                    case 1:
                        this.y = value;
                        break;

                    default:
                        throw new IndexOutOfRangeException("Invalid GTVector2 index!");
                }
            }
        }
        public void Set(float new_x, float new_y)
        {
            this.x = new_x;
            this.y = new_y;
        }

        public static GTVector2 Lerp(GTVector2 from, GTVector2 to, float t)
        {
            t = Mathf.Clamp01(t);
            return new GTVector2(from.x + ((to.x - from.x) * t), from.y + ((to.y - from.y) * t));
        }

        public static GTVector2 MoveTowards(GTVector2 current, GTVector2 target, float maxDistanceDelta)
        {
            GTVector2 vector = target - current;
            float magnitude = vector.magnitude;
            if ((magnitude > maxDistanceDelta) && (magnitude != 0f))
            {
                return (current + ((GTVector2)((vector / magnitude) * maxDistanceDelta)));
            }
            return target;
        }

        public static GTVector2 Scale(GTVector2 a, GTVector2 b)
        {
            return new GTVector2(a.x * b.x, a.y * b.y);
        }

        public void Scale(GTVector2 scale)
        {
            this.x *= scale.x;
            this.y *= scale.y;
        }

        public void Normalize()
        {
            float magnitude = this.magnitude;
            if (magnitude > 1E-05f)
            {
                this = (GTVector2)(this / magnitude);
            }
            else
            {
                this = zero;
            }
        }

        public GTVector2 normalized
        {
            get
            {
                GTVector2 vector = new GTVector2(this.x, this.y);
                vector.Normalize();
                return vector;
            }
        }
        public override string ToString()
        {
            object[] args = new object[] { this.x, this.y };
            //return UnityString.Format("({0:F1}, {1:F1})", args);
            return string.Format("({0:F1}, {1:F1})", args);
        }

        public string ToString(string format)
        {
            object[] args = new object[] { this.x.ToString(format), this.y.ToString(format) };
            //return UnityString.Format("({0}, {1})", args);
            return string.Format("({0}, {1})", args);
        }

        public override int GetHashCode()
        {
            return (this.x.GetHashCode() ^ (this.y.GetHashCode() << 2));
        }

        public override bool Equals(object other)
        {
            if (!(other is GTVector2))
            {
                return false;
            }
            GTVector2 vector = (GTVector2)other;
            return (this.x.Equals(vector.x) && this.y.Equals(vector.y));
        }

        public static float Dot(GTVector2 lhs, GTVector2 rhs)
        {
            return ((lhs.x * rhs.x) + (lhs.y * rhs.y));
        }

        public float magnitude
        {
            get
            {
                return Mathf.Sqrt((this.x * this.x) + (this.y * this.y));
            }
        }
        public float sqrMagnitude
        {
            get
            {
                return ((this.x * this.x) + (this.y * this.y));
            }
        }
        public static float Angle(GTVector2 from, GTVector2 to)
        {
            return (Mathf.Acos(Mathf.Clamp(Dot(from.normalized, to.normalized), -1f, 1f)) * 57.29578f);
        }

        public static float Distance(GTVector2 a, GTVector2 b)
        {
            GTVector2 vector = a - b;
            return vector.magnitude;
        }

        public static GTVector2 ClampMagnitude(GTVector2 vector, float maxLength)
        {
            if (vector.sqrMagnitude > (maxLength * maxLength))
            {
                return (GTVector2)(vector.normalized * maxLength);
            }
            return vector;
        }

        public static float SqrMagnitude(GTVector2 a)
        {
            return ((a.x * a.x) + (a.y * a.y));
        }

        public float SqrMagnitude()
        {
            return ((this.x * this.x) + (this.y * this.y));
        }

        public static GTVector2 Min(GTVector2 lhs, GTVector2 rhs)
        {
            return new GTVector2(Mathf.Min(lhs.x, rhs.x), Mathf.Min(lhs.y, rhs.y));
        }

        public static GTVector2 Max(GTVector2 lhs, GTVector2 rhs)
        {
            return new GTVector2(Mathf.Max(lhs.x, rhs.x), Mathf.Max(lhs.y, rhs.y));
        }

        public static GTVector2 zero
        {
            get
            {
                return new GTVector2(0f, 0f);
            }
        }
        public static GTVector2 one
        {
            get
            {
                return new GTVector2(1f, 1f);
            }
        }
        public static GTVector2 up
        {
            get
            {
                return new GTVector2(0f, 1f);
            }
        }
        public static GTVector2 right
        {
            get
            {
                return new GTVector2(1f, 0f);
            }
        }
        public static GTVector2 operator +(GTVector2 a, GTVector2 b)
        {
            return new GTVector2(a.x + b.x, a.y + b.y);
        }

        public static GTVector2 operator -(GTVector2 a, GTVector2 b)
        {
            return new GTVector2(a.x - b.x, a.y - b.y);
        }

        public static GTVector2 operator -(GTVector2 a)
        {
            return new GTVector2(-a.x, -a.y);
        }

        public static GTVector2 operator *(GTVector2 a, float d)
        {
            return new GTVector2(a.x * d, a.y * d);
        }

        public static GTVector2 operator *(float d, GTVector2 a)
        {
            return new GTVector2(a.x * d, a.y * d);
        }

        public static GTVector2 operator /(GTVector2 a, float d)
        {
            return new GTVector2(a.x / d, a.y / d);
        }

        public static bool operator ==(GTVector2 lhs, GTVector2 rhs)
        {
            return (SqrMagnitude(lhs - rhs) < 9.999999E-11f);
        }

        public static bool operator !=(GTVector2 lhs, GTVector2 rhs)
        {
            return (SqrMagnitude(lhs - rhs) >= 9.999999E-11f);
        }

        public static implicit operator GTVector2(Vector3 v)
        {
            return new GTVector2(v.x, v.y);
        }

        public static implicit operator Vector3(GTVector2 v)
        {
            return new Vector3(v.x, v.y, 0f);
        }
    }
     * */
}
