/***************************
 * (C) 2010 Claudio Rocchini
 * GPL License
 ***************************/
#include <stdio.h>
#include <math.h>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>

const double PI = 3.1415926535897932384626433832795;
typedef std::pair<int, int> edge;

static inline unsigned char f2b(double f)
{
    if (f < 0)
        f = 0;
    if (f > 1)
        f = 1;
    int i = int(f * 256);
    if (i > 255)
        i = 255;
    else if (i < 0)
        i = 0;
    return i;
}

void HSV2RGB(double h, double s, double v, unsigned char rgb[3])
{
    if (s == 0)
    {
        rgb[0] = rgb[1] = rgb[2] = f2b(v);
    }
    else
    {
        double v_h = h * 6;
        double v_i = floor(v_h);
        double v_1 = v * (1 - s);
        double v_2 = v * (1 - s * (v_h - v_i));
        double v_3 = v * (1 - s * (1 - (v_h - v_i)));
        double v_r, v_g, v_b;
        if (v_i == 0)
        {
            v_r = v;
            v_g = v_3;
            v_b = v_1;
        }
        else if (v_i == 1)
        {
            v_r = v_2;
            v_g = v;
            v_b = v_1;
        }
        else if (v_i == 2)
        {
            v_r = v_1;
            v_g = v;
            v_b = v_3;
        }
        else if (v_i == 3)
        {
            v_r = v_1;
            v_g = v_2;
            v_b = v;
        }
        else if (v_i == 4)
        {
            v_r = v_3;
            v_g = v_1;
            v_b = v;
        }
        else
        {
            v_r = v;
            v_g = v_1;
            v_b = v_2;
        };

        rgb[0] = f2b(v_r);
        rgb[1] = f2b(v_g);
        rgb[2] = f2b(v_b);
    }
}

class permu
{
public:
    std::vector<size_t> p;
    void ident(size_t n)
    {
        p.resize(n);
        for (size_t i = 0; i < n; ++i)
            p[i] = i;
    }
};

void copy(permu &dst, const permu &src)
{
    dst.p.resize(src.p.size());
    std::copy(src.p.begin(), src.p.end(), dst.p.begin());
}

void apply(permu &dst, const size_t perm[])
{
    permu t;
    copy(t, dst);
    for (size_t i = 0; i < dst.p.size(); ++i)
        dst.p[i] = t.p[perm[i]];
}

void apply(permu &dst, const int perm[])
{
    permu t;
    copy(t, dst);
    for (size_t i = 0; i < dst.p.size(); ++i)
        dst.p[i] = t.p[perm[i]];
}

bool operator==(const permu &a, const permu &b)
{
    std::vector<size_t>::const_iterator i, j;
    for (i = a.p.begin(), j = b.p.begin(); i != a.p.end(); ++i, ++j)
        if (*i != *j)
            return false;
    return true;
}

bool operator<(const permu &a, const permu &b)
{
    std::vector<size_t>::const_iterator i, j;
    for (i = a.p.begin(), j = b.p.begin(); i != a.p.end(); ++i, ++j)
        if (*i != *j)
            return *i < *j;
    return false;
}

size_t fix_point(const permu &pe)
{
    size_t fix = 0;
    for (size_t j = 0; j < pe.p.size(); ++j)
        if (pe.p[j] == j)
            ++fix;
    return fix;
}

size_t cicle_size(const permu &pe)
{
    permu t;
    copy(t, pe);
    size_t cs = 0;
    for (;;)
    {
        apply(t, &pe.p.front());
        ++cs;
        if (t == pe)
            break;
    }
    return cs;
}

size_t sub_loops(const permu &pe, std::vector<std::vector<size_t>> &loops)
{
    std::vector<bool> done(pe.p.size());
    std::fill(done.begin(), done.end(), false);
    loops.clear();
    for (;;)
    {
        size_t i;
        for (i = 0; i < pe.p.size(); ++i)
            if (!done[i])
                break;
        if (i == pe.p.size())
            break;
        loops.push_back(std::vector<size_t>());
        size_t j = i;
        do
        {
            done[j] = true;
            loops.back().push_back(j);
            j = pe.p[j];
        } while (j != i);
    }
    return loops.size();
}

void out_nauty(int n, const std::vector<std::pair<int, int>> &edges, const char *filename)
{
    std::vector<std::vector<int>> vv;
    vv.resize(n);
    std::vector<std::pair<int, int>>::const_iterator i;
    for (i = edges.begin(); i != edges.end(); ++i)
        if ((*i).first < (*i).second)
            vv[(*i).first].push_back((*i).second);
        else
            vv[(*i).second].push_back((*i).first);

    std::vector<std::vector<int>>::iterator j;
    for (j = vv.begin(); j != vv.end(); ++j)
        std::sort(j->begin(), j->end());

    FILE *fo = fopen(filename, "w");
    fprintf(fo, "n=%d\ng\n", n);
    for (j = vv.begin(); j != vv.end(); ++j)
    {
        if (j != vv.begin())
            fprintf(fo, ";\n");
        std::vector<int>::iterator k;
        for (k = j->begin(); k != j->end(); ++k)
        {
            if (k != j->begin())
                fprintf(fo, " ");
            fprintf(fo, "%d", *k);
        }
    }
    fprintf(fo, ".\n");
    fprintf(fo, "p\nx\no\nq\n");
    fclose(fo);
}

void load_nauty(int NV, const char *filename, std::vector<std::vector<int>> &auto_base)
{
    const int BSIZE = 1024;
    static char buff[1024];
    auto_base.clear();
    FILE *fp = fopen(filename, "r");
    auto_base.push_back(std::vector<int>());
    while (fgets(buff, BSIZE, fp))
    {
        if (strstr(buff, "grpsize"))
            break;
        else if (strstr(buff, "level"))
            auto_base.push_back(std::vector<int>());
        else
        {
            const char *sep = " \n\r\t";
            char *p = strtok(buff, sep);
            while (p)
            {
                if (auto_base.back().size() == size_t(NV))
                    auto_base.push_back(std::vector<int>());
                auto_base.back().push_back(atoi(p));
                p = strtok(0, sep);
            }
        }
    }
    fclose(fp);
    auto_base.pop_back();
}

// n = master set size, m= subsets size
void make_subsets(int m, int n, std::vector<std::vector<int>> &subs)
{
    std::vector<int> ss(m);
    for (int i = 0; i < m; ++i)
        ss[i] = i;
    subs.clear();
    for (;;)
    {
        subs.push_back(ss);
        int i = m - 1;
        for (;;)
        {
            if (++ss[i] < n)
            {
                if (i == m - 1)
                    break;
                ss[i + 1] = ss[i];
                ++i;
            }
            else if (--i < 0)
                break;
        }
        if (i < 0)
            break;
    }
}

// number of commons element. a,b supposed ordered
int commons(std::vector<int> &a, std::vector<int> &b)
{
    if (a.back() < b.front() || a.front() > b.back())
        return 0;
    int c = 0;
    std::vector<int>::const_iterator ia, ib;
    for (ia = a.begin(), ib = b.begin(); ia != a.end() && ib != b.end();)
    {
        if (*ia == *ib)
        {
            ++c;
            ++ia;
            ++ib;
        }
        else if (*ia < *ib)
            ++ia;
        else
            ++ib;
    }
    return c;
}

// n = numero di caratteri, m = lunghezza stringhe, l=sotto-insiemi unici
void make_steiner_system(int l, int m, int n, std::vector<std::vector<int>> &out_blocks)
{
    std::vector<std::vector<int>> blocks;
    make_subsets(m, n, blocks);
    size_t i, j;
    std::vector<bool> oks(blocks.size());
    std::fill(oks.begin(), oks.end(), true);
    for (i = 0; i < blocks.size() - 1; ++i)
        if (oks[i])
            for (j = i + 1; j < blocks.size(); ++j)
                if (oks[j])
                    if (commons(blocks[i], blocks[j]) >= l)
                        oks[j] = false;
    out_blocks.clear();
    for (i = 0; i < blocks.size(); ++i)
        if (oks[i])
            out_blocks.push_back(blocks[i]);
}

bool analyze_sym(int NV, permu &p, std::vector<int> &out_perm)
{
    if (fix_point(p) != 0)
        return false;
    size_t cs = cicle_size(p);
    if (cs < 4 || NV % cs != 0)
        return false;
    std::vector<std::vector<size_t>> loops;
    if (size_t(NV) == cs * loops.size())
    {
        std::vector<std::vector<size_t>>::iterator q;
        size_t iq;
        for (iq = 0, q = loops.begin(); q != loops.end(); ++iq, ++q)
        {
            std::vector<size_t>::iterator w;
            size_t iw;
            for (iw = 0, w = q->begin(); w != q->end(); ++iw, ++w)
                out_perm[iq + loops.size() * iw] = *w;
        }
        return true;
    }
    return false;
}

void find_symmetric(int NV, const std::vector<std::vector<int>> &auto_base, std::vector<int> &out_perm)
{
    std::set<permu> perms;
    std::vector<permu> active;
    out_perm.resize(NV);

    permu cu;
    cu.ident(NV);
    perms.insert(cu);
    active.push_back(cu);

    while (!active.empty())
    {
        std::vector<permu>::iterator i;
        std::pair<std::set<permu>::iterator, bool> r;
        std::vector<permu> old_active;
        std::swap(old_active, active);
        for (i = old_active.begin(); i != old_active.end(); ++i)
        {
            for (size_t j = 0; j < auto_base.size(); ++j)
            {
                copy(cu, *i);
                apply(cu, &auto_base[j].front());
                r = perms.insert(cu);
                if (r.second)
                {
                    if (analyze_sym(NV, cu, out_perm))
                        return;
                    active.push_back(cu);
                }
            }
        }
    }
}

void save_svg_color(const char *filename, int NV, std::vector<edge> &edges, const int perm[])
{
    const double SX = 800;
    const double SY = 800;
    const double RR = 2;
    const double BO = 10;

    std::vector<double> px(NV);
    std::vector<double> py(NV);

    FILE *fp = fopen(filename, "w");
    fprintf(fp,
            "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n"
            "<svg\n"
            "xmlns:svg=\"http://www.w3.org/2000/svg\"\n"
            "xmlns=\"http://www.w3.org/2000/svg\"\n"
            "version=\"1.0\"\n"
            "width=\"%g\"\n"
            "height=\"%g\"\n"
            "id=\"rockini\">\n",
            SX, SY);

    int i;
    const double R = ((SX - BO * 2) / 2);

    for (i = 0; i < NV; ++i)
    {
        const double a = 2 * PI * i / NV;
        px[perm[i]] = SX / 2 + R * cos(a);
        py[perm[i]] = SY / 2 + R * sin(a);
    }

    std::set<int> dist;
    for (i = 0; i < int(edges.size()); ++i)
    {
        double dx = px[edges[i].first] - px[edges[i].second];
        double dy = py[edges[i].first] - py[edges[i].second];
        int di = int(sqrt(dx * dx + dy * dy) + 0.5);
        dist.insert(di);
    }
    std::vector<int> vdist;
    std::set<int>::iterator id;
    for (id = dist.begin(); id != dist.end(); ++id)
        vdist.push_back(*id);

    for (size_t co = 0; co < vdist.size(); ++co)
    {
        unsigned char rgb[3];
        HSV2RGB(double(co) * 2 / (3 * vdist.size()), 0.9, 0.8, rgb);
        fprintf(fp, "<g id=\"edges\" style=\"stroke:#%02X%02X%02X;stroke-width:0.1;\">\n",
                rgb[0], rgb[1], rgb[2]);
        for (i = 0; i < int(edges.size()); ++i)
        {
            double dx = px[edges[i].first] - px[edges[i].second];
            double dy = py[edges[i].first] - py[edges[i].second];
            int di = int(sqrt(dx * dx + dy * dy) + 0.5);
            if (di != vdist[co])
                continue;
            fprintf(fp,
                    "<line x1=\"%5.1lf\" y1=\"%5.1lf\" x2=\"%5.1lf\" y2=\"%5.1lf\"/>\n", px[edges[i].first], py[edges[i].first], px[edges[i].second], py[edges[i].second]);
        }
        fprintf(fp, "</g>\n");
    }

    fprintf(fp, "<g id=\"nodes\" style=\"stroke:#000;stroke-width:1;stroke-opacity:1.0;fill:#040000\">\n");
    for (i = 0; i < NV; ++i)
        fprintf(fp, "<circle cx=\"%5.1lf\" cy=\"%5.1lf\" r=\"%5.1lf\"/>\n", px[i], py[i], RR);
    fprintf(fp, "</g>\n");

    fprintf(fp, "</svg>\n");
    fclose(fp);
}

int main()
{
    size_t i, j, k, h;

    // Make McLaughlin Graph
    const int NVMC = 275; // 22=steiner char >0, 77 = B blocks contains 0, 176 = C block not-contains
    std::vector<std::vector<int>> blocks;
    make_steiner_system(4, 7, 23, blocks);

    std::vector<size_t> B;
    std::vector<size_t> C;
    for (i = 0; i < blocks.size(); ++i)
        if (std::find(blocks[i].begin(), blocks[i].end(), 0) != blocks[i].end())
            B.push_back(i);
        else
            C.push_back(i);

    std::vector<edge> edges_mc;

    for (i = 0; i < 22; ++i)
        for (j = 0; j < B.size(); ++j)
        {
            k = B[j];
            if (std::find(blocks[k].begin(), blocks[k].end(), i + 1) == blocks[k].end())
                edges_mc.push_back(edge(i, j + 22));
        }

    for (i = 0; i < B.size() - 1; ++i)
        for (j = i + 1; j < B.size(); ++j)
            if (commons(blocks[B[i]], blocks[B[j]]) == 1)
                edges_mc.push_back(edge(i + 22, j + 22));

    for (i = 0; i < 22; ++i)
        for (j = 0; j < C.size(); ++j)
        {
            k = C[j];
            if (std::find(blocks[k].begin(), blocks[k].end(), i + 1) != blocks[k].end())
                edges_mc.push_back(edge(i, j + 99));
        }

    for (i = 0; i < B.size(); ++i)
    {
        k = B[i];
        for (j = 0; j < C.size(); ++j)
        {
            h = C[j];
            if (commons(blocks[k], blocks[h]) == 3)
                edges_mc.push_back(edge(i + 22, j + 99));
        }
    }

    for (i = 0; i < C.size() - 1; ++i)
        for (j = i + 1; j < C.size(); ++j)
            if (commons(blocks[C[i]], blocks[C[j]]) == 1)
                edges_mc.push_back(edge(i + 99, j + 99));

    // Make Local McLaughlin Graph
    std::vector<bool> deleted(NVMC);
    std::fill(deleted.begin(), deleted.end(), false);
    deleted[0] = true;
    std::vector<edge>::iterator ie;
    for (ie = edges_mc.begin(); ie != edges_mc.end(); ++ie)
    {
        if ((*ie).first == 0)
            deleted[(*ie).second] = true;
        if ((*ie).second == 0)
            deleted[(*ie).first] = true;
    }

    size_t NV = 0;
    std::vector<int> reindex(NVMC);
    for (i = 0; i < deleted.size(); ++i)
        if (!deleted[i])
            reindex[i] = NV++;
        else
            reindex[i] = -1;
    printf("%u vertices\n", NV);

    std::vector<edge> edges;
    for (ie = edges_mc.begin(); ie != edges_mc.end(); ++ie)
    {
        int rf = reindex[(*ie).first];
        int rs = reindex[(*ie).second];
        if (rf != -1 && rs != -1)
            edges.push_back(edge(rf, rs));
    }
    printf("%u edges\n", edges.size());

    // nauty
    out_nauty(NV, edges, "lmclaughlin_i.txt");
    system("nauty < lmclaughlin_i.txt > lmclaughlin_o.txt");
    std::vector<std::vector<int>> auto_base;
    load_nauty(NV, "lmclaughlin_o.txt", auto_base);

    std::vector<int> out_perm;
    find_symmetric(NV, auto_base, out_perm);
    save_svg_color("c:\\temp\\lmclaughlin.svg", NV, edges, &out_perm.front());

    return 0;
}